#include "Game.h"
#include "Snake.h"
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
    initBorders();
    for(int i = 0; i < GRID_WIDTH; i++)
    {
        for(int j = 0; j < GRID_HEIGHT; j++)
        {
            std::cout << grid[i][j];
        }
        std::cout << '\n';
    }
}

void Game::start(Snake *snake)
{
    if(snake != nullptr)
    {
        Part headPart;
        headPart.x = GRID_WIDTH / 2;
        headPart.y = GRID_HEIGHT / 2;
        snake->body.push_back(headPart);
    }
}

void Game::update(Snake snake)
{
    for( auto part : snake.body)
    {
        grid[part.x][part.y] = '#';
    }
}


void Game::initBorders()
{
    for(int i = 0; i < GRID_WIDTH; i++)
    {
        for(int j = 0; j < GRID_HEIGHT; j++)
        {
            if(i == 0 || i == GRID_WIDTH - 1)
            {
                grid[i][j] = '-';
            }
            if(j == 0 || j == GRID_HEIGHT - 1)
            {
                grid[i][j] = '|';
            }
        }
    }
}