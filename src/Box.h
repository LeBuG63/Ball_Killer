#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <iostream>
#include <string>

class Box
{
public:
    Box(std::string filePath, unsigned int y, unsigned int x)
    {
        if((m_surface = IMG_Load(filePath.c_str())) == NULL)
            std::cerr << "Error to load: \" " << filePath.c_str() << " \"." << std::endl;

        pos.x = x;
        pos.y = y;
    }

    ~Box()
    {
        SDL_FreeSurface(m_surface);
    }

    void blit(SDL_Surface *);

    SDL_Rect    pos;

private:
    SDL_Surface *m_surface;
};

#endif // BOX_H_INCLUDED
