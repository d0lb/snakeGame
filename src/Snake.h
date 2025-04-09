#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
struct Part{
    int x,y;
};


class Snake{
    public:
        std::vector<Part> body;
        Snake(){
            body = std::vector<Part>();
        }
};

#endif