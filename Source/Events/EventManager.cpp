#include <iostream>
#include "../../Header/Events/EventManager.h"

namespace Events
{
	void EventManager::PollEvents(RenderWindow* game_window)
	{
		sf::Event event;
		while (game_window->pollEvent(event))
		{
			//Handle window close event
			if (event.type == sf::Event::Closed)
			{
				game_window->close();
			}
			if (IsKeyPressed(Keyboard::Escape))
			{
				game_window->close();
			}
			if (IsLeftMouseButtonClicked())
			{
				Vector2i position = Mouse::getPosition(*game_window);
				cout << "Left mouse cick at " << position.x << "," << position.y << endl;
			}
		}
	}
	bool EventManager::IsKeyPressed(Keyboard::Key key)
	{
		//Detect is a specific key is pressed
		return Keyboard::isKeyPressed(key);
	}
	bool EventManager::IsLeftMouseButtonClicked()
	{
		//Detect if the left mouse button is pressed
		return Mouse::isButtonPressed(Mouse::Left);
	}
}