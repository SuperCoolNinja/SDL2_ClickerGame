#include "GameProperty.h"
#include <math.h>       /* sqrt */
#include <time.h>
#include <iostream>

int const MIN_WIDTH = 100;
int const MIN_RADIUS = 20;
int const MAX_RADIUS = 100;
int const MAX_WIDTH = 640 / 2;
int const MAX_HEIGHT = 580 / 2;


void BeginGame()
{
    //INIT RANDOM VALUE TO 0 : 
    std::srand(time(NULL));

    SDL_Window* Main_Window = nullptr;
    SDL_Renderer* Main_Renderer = nullptr;
    GameProperty gameProper;
    SDL_Event event;
    Colors colors;
    Uint32 buttons;

    /* Before we can render anything, we need a window and a renderer */
    Main_Window = SDL_CreateWindow("Clicker Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 580, 0);
    Main_Renderer = SDL_CreateRenderer(Main_Window, -1, SDL_RENDERER_ACCELERATED);

    if (Main_Window != nullptr && Main_Renderer != nullptr)
    {
        SDL_Log("Clicker game window created.");

        auto xMouse = 0;
        auto yMouse = 0;
        auto canClose = false;
        auto randomPosX = 100;
        auto randomPosY = 100;
        auto radius = 100;

        while (!canClose)
        {
            //Mouse Event :
            SDL_WaitEvent(&event);
            SDL_PumpEvents();
            buttons = SDL_GetMouseState(&xMouse, &yMouse);

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                float distRadius = gameProper.distance(xMouse, yMouse, gameProper.GetPropertyCircle().x, gameProper.GetPropertyCircle().y);

                if (distRadius < radius)
                {
                    SDL_Log("CIRCLE TOUCH !");

                    //Create a random position for the circle : 
                    randomPosX = rand() % MAX_WIDTH + MIN_WIDTH;
                    randomPosY = rand() % MAX_HEIGHT + MIN_WIDTH;

                    //Change to a random color : 
                    colors.R = rand() % 256;
                    colors.G = rand() % 256;
                    colors.B = rand() % 256;

                    //Change to a random radius : 
                    radius = (rand() % (MAX_RADIUS - MIN_RADIUS) + MIN_RADIUS);
                }
            }


            //Event that allow us to check if we press the X to close : 
            switch (event.type)
            {
            case SDL_QUIT:
                canClose = true;
                break;
            }

            //Background color : 
            SDL_SetRenderDrawColor(Main_Renderer, 0, 0, 0, 255);

            //Clean the color render : 
            SDL_RenderClear(Main_Renderer);

            //Draw Circle : 
            gameProper.DrawCircle(Main_Renderer, randomPosX, randomPosY, radius, colors);

            //Render the circle on the screen :
            SDL_RenderPresent(Main_Renderer);
        }


        //Once we close the app, clean and free everything in the back before to close it :
        SDL_DestroyRenderer(Main_Renderer);
        SDL_DestroyWindow(Main_Window);
        SDL_Quit();
    }
}