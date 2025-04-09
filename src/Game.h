#ifndef GAME_H
#define GAME_H
#include <vector>
#include "Snake.h"
#include <cstdlib>
#include <ctime>
const int FRAMERATE = 30;
const int GRID_WIDTH = 10;
const int GRID_HEIGHT = 30;

void clearTerminal();

struct Food{
    int x,y;
};

class Snake;

class Game{
    public:
        std::vector<std::vector<char>> grid;
        Food food;
        bool checkDeath(Snake snake);
        Game(){
            grid = std::vector<std::vector<char>>(GRID_WIDTH, std::vector<char>(GRID_HEIGHT, ' '));
            food.x = rand() % (GRID_WIDTH - 5) + 3;
            food.y = rand() % (GRID_HEIGHT - 15) + 2;
            score = 0;
        }
        void start(Snake *snake);
        void generateFood(Snake snake);
        void display();
        void update(Snake *snake);
    private:
        void initBorders();
        int score;
        
};

#endif