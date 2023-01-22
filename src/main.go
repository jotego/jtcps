package main

import(
	"encoding/xml"
	"io/fs"
	"io/ioutil"
	"os"
	"fmt"
	"regexp"
	"strings"
	"path/filepath"
)

type MRApart struct {
	Data string `xml:",chardata"`
	Name string `xml:"name,attr"`
	Repeat int `xml:"repeat,attr"`

}

type MRArom struct {
	Index int `xml:"index,attr"`
	Parts []MRApart `xml:"part"`
}

type MRA struct {
	Rbf string `xml:"rbf"`
	Setname string `xml:"setname"`
	Roms []MRArom `xml:"rom"`
}

func parse_mra( path string, de fs.DirEntry, e error ) error {
	if e!=nil || de.IsDir() || !strings.HasSuffix(de.Name(),".mra") {
		return nil
	}
	full_path := filepath.Join( os.Getenv("JTBIN"), path)
	raw, e := ioutil.ReadFile(full_path)
	if e != nil {
		fmt.Println(e)
		return e
	}
	var mra MRA
	xml.Unmarshal( raw, &mra )
	if mra.Rbf != "jtcps1" {
		return nil
	}
	// Collect part text
	all_data := ""
	for _, each := range mra.Roms {
		if each.Index!=0 {
			continue
		}
		for _, p := range each.Parts {
			if p.Data=="" {
				break
			}
			reps := 1
			if p.Repeat!=0 {
				reps = p.Repeat
			}
			for reps>0 {
				all_data += " " + strings.TrimSpace(p.Data)
				reps--
			}
		}
	}
	all_data = strings.ToUpper(all_data)
	re := regexp.MustCompile("[\n\t ]+")
	all_data = re.ReplaceAllString( all_data, " ")
	re = regexp.MustCompile("( FF)+$")
	all_data = re.ReplaceAllString( all_data, "")
	var byteparts []string
	byteparts = strings.Split(all_data," ")
	if len(byteparts)>16 {
		sn := "\""+mra.Setname+"\","
		fmt.Printf("\t{ setname=%-14s pointer=16, data=\"%s\" },\n", sn, strings.Join(byteparts[17:]," ") )
	}
	return nil
}

func main() {
	os.Chdir( os.Getenv("JTBIN") )
	fs.WalkDir( os.DirFS("."),"mra", parse_mra )
}