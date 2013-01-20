#include "Write.h"

void Write::print(std::string str)
{
    m_text = TTF_RenderText_Solid(m_font, str.c_str(), m_color);

    SDL_BlitSurface(m_text, NULL, m_screen, &m_pos);
}
