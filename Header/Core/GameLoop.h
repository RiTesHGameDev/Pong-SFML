#pragma once
#include <SFML/Graphics.hpp>
#include "../Core/GameWindowManager.h"
#include "../Events/EventManager.h"
#include "../Gameplay/GameplayManager.h"
#include "../Sounds/SoundManager.h"

using namespace sf;
using namespace std;
using namespace Core;
using namespace Events;
using namespace Gameplay;
using namespace Sounds;

namespace Core
{
	class GameLoop
	{
	private:
		GameWindowManager* game_window_manager;
		GameplayManager* gameplay_manager;
		EventManager* event_manager;
	public:
		void Initialize();
		bool IsGameRunning();
		void PollEvent();
		void Update();
		void Render();
	};
}