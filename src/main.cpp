#include "Game.h"
#include "Snake.h"

int main()
{
    Game game;
    Snake snake;
    game.start(&snake);
    game.update(snake);
    game.display();
    return 0;
}