#include <iostream>
#include "game.h"

int main()
{
    Game::Init();
    Game::Loop();
    Game::ShutDown();
}
