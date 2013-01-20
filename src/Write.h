#ifndef WRITE_H_INCLUDED
#define WRITE_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include <iostream>

class Write
{
public:
    Write(SDL_Surface *screen, std::string name, unsigned int y, unsigned int x, Uint8 r, Uint8 g, Uint8 b, unsigned int size)
    {
        m_color = {r, g, b};
        m_screen = screen;

        m_font = TTF_OpenFont(name.c_str(), size);
        if(m_font == NULL)
            std::cerr << "Error to load: \" " << name.c_str() << "\"." << std::endl;
        m_pos.x = x;
        m_pos.y = y;
    }

    ~Write()
    {
        TTF_CloseFont(m_font);
        SDL_FreeSurface(m_text);
        SDL_FreeSurface(m_screen);
    }

    void print(std::string);

private:
    TTF_Font        *m_font;
    SDL_Color       m_color;

    SDL_Rect        m_pos;
    SDL_Surface     *m_text;
    SDL_Surface     *m_screen;
};

#endif // WRITE_H_INCLUDED
