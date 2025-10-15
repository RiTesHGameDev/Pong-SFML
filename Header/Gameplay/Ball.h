#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace Gameplay
{
	class Ball
	{
	private:
		Sprite pong_ball_sprite;
		const float radius = 10.0f;
		const float position_x = 615.0f;
		const float position_y = 335.0f;

		Texture pong_ball_texture;
		string texture_path = "Assets/Textures/Ball.png";

		const float scale_x = 0.05f;
		const float scale_y = 0.05f;

		void LoadTexture();
		void InitializeVariables();
	public:
		Ball();
		void Update();
		void Render(RenderWindow* game_window);
	};
}