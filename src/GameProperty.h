#pragma once

#include "SDL.h"

//Structure :
struct PropertyCircle
{
	int x;
	int y;
};

/**
 * Colors Struct :
 */
struct Colors
{
	int R = 255;
	int G = 0;
	int B = 0;
	int A = 255;
};

class GameProperty
{
public:
	GameProperty();
	~GameProperty() = default;

	/**
	* This method return a struct which contain the property of the circle.
	* int = horizontal.
	* int = vertical.
	* int = radius.
	*/
	PropertyCircle GetPropertyCircle();

	void DrawCircle(SDL_Renderer* renderer, int posX, int posY, int radius, Colors colors);
	float distance(const int x1, const int y1, const int x2, const int y2);

private:
	
	//Circle Property :
	PropertyCircle ProperCircle;
	SDL_Color cCircle;
};

