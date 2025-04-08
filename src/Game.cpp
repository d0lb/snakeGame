#include "Game.h"
#include <cstdlib>
#include <iostream>

void clearTerminal()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Game::display()
{
    clearTerminal();
    for(int i = 0; i < GRID_WIDTH; i++)
    {
        for(int j = 0; j < GRID_HEIGHT; j++)
        {
            std::cout << grid[i][j];
        }
        std::cout << '\n';
    }
}