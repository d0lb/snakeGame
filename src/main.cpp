#include "Game.h"
#include "Snake.h"
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif
#include <iostream>

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Game game;
    Snake snake;
    game.start(&snake);
    while(1)
    {
        snake.move(&game);
        game.update(&snake);
        game.display();
        #ifdef _WIN32
            Sleep(300);
        #else
            usleep(300000);
        #endif
        if(game.checkDeath(snake))
        {
            break;
        }
          
    }
    
    return 0;
}