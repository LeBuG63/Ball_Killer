#include "functions.h"

#include <cstdlib>
#include <cstdio>

unsigned int rand_v()
{
    return((rand() % ((1) + 1)) ? 1 : -1);
}

bool collision(Player *p, Ennemy *e)
{
    if(!(p->getX() >= (e->getX() + e->getW())
    || p->getX() +  p->getW() <= e->getX()
    || p->getY() >= (e->getY() + e->getH())
    || p->getY() +   e->getH() <= e->getY()))
    {
        std::cout << "[Collision] Player - Ennemy" << std::endl;
        return true;
    }
    return false;
}

unsigned int rand_n(unsigned int a, unsigned int b)
{
    return((rand() % (b - a + 1)) + a);
}
