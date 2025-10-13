#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Header/Core/GameWindowManager.h"
#include "../../Header/Events/EventManager.h"

int main()
{
    //Create our window manager instance
    Core::GameWindowManager gameWindowManager;
    //Create object of event manager
    Events::EventManager eventManager;

    //intialize the window
    gameWindowManager.initialize();

    while (gameWindowManager.isGameRunning())
    {
        eventManager.pollEvents(gameWindowManager.getGameWindow());
        gameWindowManager.render();
    }

    return 0;
}