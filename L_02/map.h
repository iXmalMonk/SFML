#ifndef _MAP_H
#define _MAP_H

#include <SFML/Graphics.hpp>

using namespace sf;

const int WIDTH_MAP = 40;
const int HEIGHT_MAP = 25;

String TileMap[HEIGHT_MAP] = {
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"b                                      b",
	"b           f        f                 b",
	"b       s                      s       b",
	"b                    s                 b",
	"b                                      b",
	"b        f                             b",
	"b               bbbbbbbbb              b",
	"b               b    f  b              b",
	"b    h          b    s  b       s      b",
	"b               b       b              b",
	"b               b   bbbbb              b",
	"b               b   b           f      b",
	"b       s                              b",
	"b                                      b",
	"b                       s       h      b",
	"b            f                         b",
	"b    h                                 b",
	"b                    f                 b",
	"b          s                   s       b",
	"b                                      b",
	"b                    s                 b",
	"b     f                         f      b",
	"b                                      b",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
};

#endif
