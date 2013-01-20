#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <SDL/SDL_getenv.h>
#include <SDL/SDL_ttf.h>

#include <iostream>
#include <limits>
#include <ctime>

#include "Run.h"

int main (int argc, char** argv)
{
    freopen("CON", "w", stdout);
    freopen("CON", "r", stdin);
    freopen("CON", "w", stderr);
    putenv("SDL_VIDEO_WINDOW_POS=center");

    char c;
    bool retry = false;
    double speed = 1;
    speed = SetSpeed();

    Run ball_killer(speed);

    SDL_Surface* screen = SDL_SetVideoMode(WITDH, HEIGHT, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);

    ball_killer.add_screen(screen);

    srand(time(NULL));

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Unable to init SDL: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    if(TTF_Init() == -1)
    {
        std::cerr << "TTF_Init : " << TTF_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    atexit(TTF_Quit);
    atexit(SDL_Quit);

    if (!screen)
    {
        std::cerr << "Unable to set 640x480 video: " << SDL_GetError() << std::endl;
        return 1;
    }


    ball_killer.run();

    std::cout << "Exit...";

    return 0;
}
