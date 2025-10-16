#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace Gameplay
{
	class Paddle
	{
	private:
		Sprite paddle_sprite;
		Texture paddle_texture;
		string texture_path = "Assets/Textures/Paddle.png";

		const float paddle_speed = 0.5f;

		const float scale_x = 0.03f;
		const float scale_y = 0.8f;

		void LoadTexture();
		void InitializeVariables(float position_x, float position_y);
		void PaddleMove(bool move_up_key_pressed,
			bool move_down_key_pressed);
	public:
		Paddle(float position_x, float position_y);
		void Update(bool move_up_key_pressed,
			bool move_down_key_pressed);
		void Render(RenderWindow* game_window);
	};
}