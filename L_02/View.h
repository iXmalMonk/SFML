#ifndef _VIEW_H
#define _VIEW_H

#include <SFML/Graphics.hpp>

using namespace sf;

View view;

View getPlayerCoordinateForView(double x, double y)
{
	double temporaryX = x, temporaryY = y;

	//printf("X: %lf Y: %lf\n", x, y);

	if (x < 320) temporaryX = 320; // WIDTH_WIN / 2 = 320;
	if (y < 240) temporaryY = 240; // HEIGHT_WIN / 2 = 240;
	
	if (x > 320 + 640) temporaryX = 320 + 640; // WIDTH_WIN / 2 + W(MAP = 32) * 40 - WIDTH_WIN
	if (y > 240 + 320) temporaryY = 240 + 320; // HEIGHT_WIN / 2 + H(MAP = 32) * 25 - HEIGHT_WIN

	view.setCenter(temporaryX, temporaryY);
	return view;
}

#endif