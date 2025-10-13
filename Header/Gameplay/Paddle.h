#pragma once
#include <SFML/Graphics.hpp>


using namespace sf;

namespace Gameplay
{
	class Paddle
	{
	private:
		RectangleShape paddle_sprite;

		const float paddle_width = 20.0f;
		const float paddle_height = 140.0f;
	public:
		Paddle(float position_x, float position_y);
		void Update();
		void Render(RenderWindow* game_window);
	};
}