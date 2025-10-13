#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Events/EventManager.h"
#include "../../Header/Core/GameLoop.h"

using namespace sf;
using namespace Core;

int main()
{
    GameLoop* game_loop_manager = new GameLoop();

    game_loop_manager->Initialize();


    while (game_loop_manager->IsGameRunning())
    {
        game_loop_manager->PollEvent();
        game_loop_manager->Update();
        game_loop_manager->Render();
    }

    return 0;
}