#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace Events
{
	class EventManager {
	public:
		void pollEvents(RenderWindow* game_window); //process all events
		bool isKeyPressed(Keyboard::Key key); //check specific key
	};
}