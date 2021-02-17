/*  This file is part of JTCPS1.
    JTCPS1 program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with JTCPS1.  If not, see <http://www.gnu.org/licenses/>.

    Author: Jose Tejada Gomez. Twitter: @topapate
    Version: 1.0
    Date: 16-2-2021 */

module jtcps2_fn1(
    input   [15:0]  din,
    output  [15:0]  dout
);

wire [7:0] pre_r1, pre_r2, pre_r3, pre_r4;
wire [7:0] r1, r2, r3, r4,
           l1, l2, l3, l4;

assign r1 = pre_r1 ^ l0;
assign r2 = pre_r2 ^ l1;
assign r3 = pre_r3 ^ l2;
assign r4 = pre_r4 ^ l3;

assign l0 = { din[0],  din[1], din[3], din[5], din[8], din[9],  din[11], din[12] };
assign r0 = { din[10], din[4], din[6], din[7], din[2], din[13], din[15], din[14] };
assign l1 = r0;
assign l2 = r1;
assign l3 = r2;
assign l4 = r3;

jtcps2_sbox_fn1_r1 u_r1(
    .din    (   r0      ),
    .key    ( key1      ),
    .dout   ( pre_r1    )
);

jtcps2_sbox_fn1_r2 u_r2(
    .din    (   r1      ),
    .key    ( key2      ),
    .dout   ( pre_r2    )
);

jtcps2_sbox_fn1_r3 u_r3(
    .din    (   r2      ),
    .key    ( key3      ),
    .dout   ( pre_r3    )
);

jtcps2_sbox_fn1_r4 u_r4(
    .din    (   r3      ),
    .key    ( key4      ),
    .dout   ( pre_r4    )
);

endmodule
