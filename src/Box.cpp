#include "Box.h"

void Box::blit(SDL_Surface *screen)
{
    SDL_BlitSurface(m_surface, NULL, screen, &pos);
}
