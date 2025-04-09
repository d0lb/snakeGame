#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

enum Direction {UP, DOWN, RIGHT, LEFT};

struct Part{
    int x,y;
};


class Snake{
    public:
        std::vector<Part> body;
        void move();
        Direction direction;
        Snake(){
            body = std::vector<Part>();
            direction = UP;
        }
};

#endif