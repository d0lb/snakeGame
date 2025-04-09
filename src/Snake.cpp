#include "Snake.h"
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>
#ifdef _WIN32
    #include <conio.h>
#else   
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif



bool kbhit()
{
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);//getting curr terminal settings
    newt = oldt;
    newt.c_lflag = ~ICANON;
    newt.c_lflag = ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);//apply new settings from newt

    int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);//get curr flags
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);// set nonblock mode

    int ch = getchar(); //tryna get a char

    //recover old settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)//if we got a symbol
    {
        ungetc(ch, stdin);//return symbol back to stream
        return true;
    }

    return false;
}

void Snake::move(Game *game)
{
    std::vector<Part> tempBody = body;//temporary body coords for movement
    switch (direction) 
    {
        case UP:
            tempBody[0].x--;
            break;
        case DOWN:
            tempBody[0].x++;
            break;
        case RIGHT:
            tempBody[0].y++;
            break;
        case LEFT:
            tempBody[0].y--;
            break;
        default:
            std::cout << "ERROR: NO DIRECTION!";//just debug
            return;
    }

    for(size_t i = 1; i < tempBody.size(); i++)
    {
        tempBody[i] = body[i - 1];//copying prev positions
    }

    body = tempBody;

    if(kbhit())
    {
        char ch = getchar();
        switch (ch) {
            case 'w':
            case 'W':
                if(direction != DOWN)
                    direction = UP;
                break;
            case 's':
            case 'S':
                if(direction != UP)
                    direction = DOWN;
                break;
            case 'd':
            case 'D':
                if(direction != LEFT)
                    direction = RIGHT;
                break;
            case 'a':
            case 'A':
                if(direction != RIGHT)
                    direction = LEFT;
                break;
            default:
                break;
        }
    }
}