#ifndef ENTITIES_H_INCLUDED
#define ENTITIES_H_INCLUDED

#include <SDL/SDL.h>

#include "Box.h"

class Player
{
public:
    Player(std::string filePath, unsigned int y, unsigned int x)
    {
        m_boxPlayer = new Box(filePath, y, x);
    }

    ~Player()
    {
        delete m_boxPlayer;
    }

    void move(SDL_Event *);
    void blit(SDL_Surface *);

    unsigned int getX();
    unsigned int getY();
    unsigned int getH();
    unsigned int getW();

private:
    Box *m_boxPlayer;
};

class Ennemy
{
public:
    Ennemy(std::string filePath, unsigned int y, unsigned int x)
    {
        m_boxEnnemy = new Box(filePath, y, x);
    }
    ~Ennemy()
    {
        delete m_boxEnnemy;
    }

    void move(double);
    void blit(SDL_Surface *);

    unsigned int getX();
    unsigned int getY();
    unsigned int getH();
    unsigned int getW();

private:
    Box *m_boxEnnemy;
};

#endif // ENTITIES_H_INCLUDED
