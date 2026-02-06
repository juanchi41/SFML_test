// SFML_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"

int main()
{
    Game game; // Creating our game object.

    while (!game.GetWindow()->IsDone())
    {
        // Game loop.
        game.HandleInput();
        game.Update();
        game.Render();
    }

    return 0;
}
