#include <iostream>
#include "../../Header/Events/EventManager.h"

namespace Events
{
	void EventManager::pollEvents(RenderWindow* game_window)
	{
		sf::Event event;
		while (game_window->pollEvent(event))
		{
			//Handle window close event
			if (event.type == sf::Event::Closed)
			{
				game_window->close();
			}
			if (isKeyPressed(Keyboard::Escape))
			{
				game_window->close();
			}
			if (isLeftMouseButtonClicked())
			{
				Vector2i position = Mouse::getPosition(*game_window);
				cout << "Left mouse cick at " << position.x << "," << position.y << endl;
			}
		}
	}
	bool EventManager::isKeyPressed(Keyboard::Key key)
	{
		//Detect is a specific key is pressed
		return Keyboard::isKeyPressed(key);
	}
	bool EventManager::isLeftMouseButtonClicked()
	{
		//Detect if the left mouse button is pressed
		return Mouse::isButtonPressed(Mouse::Left);
	}
}