#include "Game.h"
#include "Snake.h"
#include <cstdlib>
#include <iostream>




void Game::generateFood(Snake snake)
{
    food.x = rand() % (GRID_WIDTH - 5) + 3;
    food.y = rand() % (GRID_HEIGHT - 15) + 3;
    for(const auto &part : snake.body)
    {
        if(food.x == part.x && food.y == part.y)
        {
            generateFood(snake);
            break;
        }
    }
}

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
    std::cout << "\n " << food.x << " " << food.y << std::endl;
}

void Game::start(Snake *snake)
{
    if(snake != nullptr)
    {
        Part headPart;
        headPart.x = GRID_WIDTH / 2;
        headPart.y = GRID_HEIGHT / 2;
        snake->body.push_back(headPart);
        headPart.x--;
        headPart.y--;
        snake->body.push_back(headPart);
    }
}

void Game::update(Snake *snake)
{
    if(snake->body[0].x == food.x && snake->body[0].y == food.y)
    {
        Part newpart = {GRID_WIDTH - 1, GRID_HEIGHT - 1};
        snake->body.push_back(newpart);
        generateFood((*snake));
    }
    for(int i = 0; i < GRID_WIDTH; i++)
    {
        for(int j = 0; j < GRID_HEIGHT; j++)
        {
            grid[i][j] = ' ';
        }
    }

    grid[food.x][food.y] = '@';

    for(auto &part : snake->body)
    {
        grid[part.x][part.y] = '#';
    }
}

bool Game::checkDeath(Snake snake)
{
    if(snake.body[0].x == 0 || snake.body[0].x == GRID_WIDTH - 1 || snake.body[0].y == 0 || snake.body[0].y == GRID_HEIGHT - 1)
    {
        return true;
    }
    for(int i = 1; i < snake.body.size(); i++)
    {
        if(snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
        {
            return true;
        }
    }
    return false;
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