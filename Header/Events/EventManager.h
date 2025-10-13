#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace Events
{
	class EventManager {
	public:
		void PollEvents(RenderWindow* game_window); //process all events
		bool IsKeyPressed(Keyboard::Key key); //check specific key
		bool IsLeftMouseButtonClicked();//check if mouse button clicked
	};
}