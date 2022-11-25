#ifndef _MAP_H
#define _MAP_H

#include <SFML/Graphics.hpp>

using namespace sf;

const int WIDTH_MAP = 40;
const int HEIGHT_MAP = 25;

String TileMap[HEIGHT_MAP] = {
	"0000000000000000000000000000000000000000",
	"0                                      0",
	"0                                      0",
	"0       1                      1       0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0               000000000              0",
	"0               0       0              0",
	"0               0       0              0",
	"0               0       0              0",
	"0               0   00000              0",
	"0                                      0",
	"0       1                              0",
	"0                                      0",
	"0                       1              0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0          1                   1       0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0000000000000000000000000000000000000000",
};

#endif
