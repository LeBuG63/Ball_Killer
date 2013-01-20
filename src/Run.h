#ifndef RUN_H_INCLUDED
#define RUN_H_INCLUDED

#include <SDL/SDL.h>
#include <string>

#define HEIGHT  480
#define WITDH   640

double SetSpeed();

class Run
{
public:
    Run(double speed)
    {
        m_running = true;
        m_speed = speed;
    }

    ~Run()
    {
        SDL_FreeSurface(m_screen);
    }

    void run();
    void change_speed(int);
    void GameOver(std::string);
    void add_screen(SDL_Surface *);

private:
    void check_event();

private:
    bool m_running;
    double  m_speed;

    SDL_Surface *m_screen;
    SDL_Event   m_event;
};

#endif // RUN_H_INCLUDED
