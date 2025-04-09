#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Game.h"
enum Direction {UP, DOWN, RIGHT, LEFT};

struct Part{
    int x,y;
};
class Game;

class Snake{
    public:
        std::vector<Part> body;
        void move(Game *game);
        Direction direction;
        Snake(){
            body = std::vector<Part>();
            direction = UP;
        }
};

#endif