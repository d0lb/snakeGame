#ifndef GAME_H
#define GAME_H
#include "Snake.h"
#include <vector>

const int FRAMERATE = 30;
const int GRID_WIDTH = 10;
const int GRID_HEIGHT = 30;

void clearTerminal();

class Game{
    public:
        Game(){
            grid = std::vector<std::vector<char>>(GRID_WIDTH, std::vector<char>(GRID_HEIGHT, ' '));
        }
        void start(Snake snake);
        void display();
    private:
        std::vector<std::vector<char>> grid;
};

#endif