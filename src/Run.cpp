#include "Run.h"

#include "Entities.h"
#include "Write.h"
#include "functions.h"

#include <iostream>

double SetSpeed()
{
    double easy   = 0.05,
            medium = 0.25,
            hard   = 0.5;

    int choice;
    double speed;

    loop:
    std::cout << "[1 - Easy]\t" << easy << std::endl << "[2 - Medium]\t" << medium << std::endl << "[3 - Hard]\t" << hard << std::endl << "[4 - Custom]" << std::endl<< std::endl;
    std::cout << "Your choice: ";

    std::cin >> choice;

    switch(choice)
    {
    case 1:
        speed = easy;
        break;
    case 2:
        speed = medium;
        break;
    case 3:
        speed = hard;
        break;
    case 4:
        std::cout << "Speed: ";
        std::cin >> speed;
        break;
    default:
        std::cout << "Error, please try" << std::endl;
        goto loop;
        break;
    }
    return speed;
}

void Run::add_screen(SDL_Surface *screen)
{
    m_screen = screen;
}

void Run::run()
{
    int score = 0;
    int time = 0, old_time = 0;

    std::string str_score = "aaaaaa";

    Write w(m_screen, "Fonts/04B_30__.TTF", 0, 10, 255, 216, 0, 25);
    Box bg("Pictures/Background.png", 0, 0);
    Player player("Pictures/player.png", 50, 50);
    Ennemy ennemy("Pictures/ennemy.png", rand_n(17, HEIGHT-17), rand_n(17, WITDH-17));

    SDL_WarpMouse(m_screen->w / 2, m_screen->h / 2);
    SDL_ShowCursor(SDL_DISABLE);

    while(m_running)
    {
        time = SDL_GetTicks();

        if((time - old_time) > 100)
        {
            score++;
            old_time = time;
        }
        while(SDL_PollEvent(&m_event))
        {
            switch(m_event.type)
            {
            case SDL_QUIT:
                m_running = false;
                break;
            }
            player.move(&m_event);
        }
        ennemy.move(m_speed);

        SDL_FillRect(m_screen, NULL, SDL_MapRGB(m_screen->format, 255, 255, 255));

        bg.blit(m_screen);
        player.blit(m_screen);
        ennemy.blit(m_screen);

        itoa(score, (char*)str_score.c_str(), 10);

        w.print("Score: " + str_score);

        if(collision(&player, &ennemy))
        {
            GameOver(str_score);
            return;
        }

        SDL_Flip(m_screen);
    }
}

void Run::change_speed(int new_speed)
{
    m_speed = new_speed;
}

void Run::check_event()
{
    switch(m_event.type)
    {
    case SDL_QUIT:
        m_running = false;
        break;
    case SDL_KEYDOWN:
        m_running = false;
        break;
    }
}

void Run::GameOver(std::string score)
{
    std::cout << "Game Over..." << std::endl;
    Write end(m_screen, "Fonts/04B_30__.TTF", HEIGHT/2 - 23, 200, 255, 216, 0, 23);
    Write score_print(m_screen, "Fonts/04B_30__.TTF", HEIGHT/2 - (-23*3), 200, 255, 216, 0, 23);
    SDL_FillRect(m_screen, NULL, SDL_MapRGB(m_screen->format, 0, 0, 0));

    end.print("You are Dead !");
    score_print.print("Score: " + score);
    SDL_Flip(m_screen);

    while(SDL_WaitEvent(&m_event) && m_event.type != SDL_KEYDOWN)
        ;
}
