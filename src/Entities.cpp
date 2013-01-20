#include "Entities.h"

#include "Run.h"
#include "functions.h"

#include <iostream>

#define SPEED       0.25
#define SIZE_BALL   30

void Player::move(SDL_Event *event)
{
    switch(event->type)
    {
    case SDL_MOUSEMOTION:
        if((m_boxPlayer->pos.x >= WITDH-(SIZE_BALL+17)))
            m_boxPlayer->pos.x = WITDH-(SIZE_BALL+17)-1;
        else
            m_boxPlayer->pos.x = event->motion.x;

        if((m_boxPlayer->pos.y >= HEIGHT-(SIZE_BALL+17)))
            m_boxPlayer->pos.y = HEIGHT-(SIZE_BALL+17)-1;
        else
            m_boxPlayer->pos.y = event->motion.y;
        break;
    }
}

void Player::blit(SDL_Surface *screen)
{
    m_boxPlayer->blit(screen);
}

unsigned int Player::getX()
{
    return m_boxPlayer->pos.x-17;
}

unsigned int Player::getY()
{
    return m_boxPlayer->pos.y-17;
}

unsigned int Player::getH()
{
    return m_boxPlayer->pos.h-17;
}

unsigned int Player::getW()
{
    return m_boxPlayer->pos.w-17;
}

void Ennemy::move(double speed_add)
{
    static int old_time;
    int time = SDL_GetTicks();
    static int xBall = rand_v(), yBall = rand_v();

    static double new_speed = 1.;

    if((time - old_time) > 0)
    {
        // X
        if(m_boxEnnemy->pos.x <= 0)
        {
            new_speed += speed_add;
            xBall = new_speed + speed_add;
            std::cout << "[Collision - Speed: " << new_speed << "] Left\n";
        }
        if(m_boxEnnemy->pos.x >= (WITDH - SIZE_BALL))
        {
            new_speed += speed_add;
            xBall = -new_speed - speed_add;
            std::cout << "[Collision - Speed: " << new_speed << "] Right\n";
        }

        // Y
        if(m_boxEnnemy->pos.y <= 0)
        {
            new_speed += speed_add;
            yBall = new_speed + speed_add;
            std::cout << "[Collision - Speed: " << new_speed << "] Up\n";
        }
        if(m_boxEnnemy->pos.y >= (HEIGHT - SIZE_BALL))
        {
            new_speed += speed_add;
            yBall = -new_speed - speed_add;
            std::cout << "[Collision - Speed: " << new_speed << "] Down\n";
        }

        if(new_speed >= 20)
            new_speed = 20;

        m_boxEnnemy->pos.x += xBall;
        m_boxEnnemy->pos.y += yBall;

        old_time = time;
    }
}

void Ennemy::blit(SDL_Surface *screen)
{
    m_boxEnnemy->blit(screen);
}

unsigned int Ennemy::getX()
{
    return m_boxEnnemy->pos.x-17;
}

unsigned int Ennemy::getY()
{
    return m_boxEnnemy->pos.y-17;
}

unsigned int Ennemy::getH()
{
    return m_boxEnnemy->pos.h-17;
}

unsigned int Ennemy::getW()
{
    return m_boxEnnemy->pos.w-17;
}
