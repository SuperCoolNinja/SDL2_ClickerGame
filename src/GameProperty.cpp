#include "GameProperty.h"


/**
 * Constructor init property :
 */
GameProperty::GameProperty()
{
    ProperCircle.x = 200;
    ProperCircle.y = 200;
    cCircle.r = 255;
    cCircle.g = 0;
    cCircle.b = 0;
    cCircle.a = 255;
}

/**
 * This method allow us to draw a circle.
 * SDL_Renderer* as parameter.
 */
void GameProperty::DrawCircle(SDL_Renderer* renderer, int posX, int posY, int radius, Colors colors)
{
    ProperCircle.x = posX;
    ProperCircle.y = posY;

    SDL_SetRenderDrawColor(renderer, colors.R, colors.G, colors.B, colors.A);
    for (int w = 0; w < radius * 2; w++)
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius))
                SDL_RenderDrawPoint(renderer, ProperCircle.x + dx, ProperCircle.y + dy);
        }
}

PropertyCircle GameProperty::GetPropertyCircle()  {return ProperCircle;}

/**
 * Function to calculate distance.
 * int = x1.
 * int = y1.
 * int = x2.
 * int = y2.
 */
float GameProperty::distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}