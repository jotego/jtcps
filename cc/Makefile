all: mmr brightness

brightnes: brightness.cc
	g++ brightness.cc -o brightness
	./brightnes

mmr: mmr.cc config.h  dip_base.h  dips.h   mappers.h  romentry.h  romsets.h mamegame.cc
	g++ mamegame.cc mmr.cc -o mmr -lxerces-c
