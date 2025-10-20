#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Utility/TimeService.h"

using namespace sf;
using namespace std;
using namespace Utility;

namespace Gameplay
{
	class Paddle
	{
	private:
		Sprite paddle_sprite;
		Texture paddle_texture;
		string texture_path = "Assets/Textures/Paddle.png";

		const float paddle_speed = 100.0f;
		float speed_multiplier = 10.0f;

		const float scale_x = 0.03f;
		const float scale_y = 0.8f;

		const float top_boundary = 20.0f;
		const float bottom_boundary = 520.0f;

		void LoadTexture();
		void Initialize(float position_x, float position_y);
		void PaddleMove(bool move_up_key_pressed, bool move_down_key_pressed, TimeService* time_service);
	public:
		Paddle(float position_x, float position_y);

		Sprite GetPaddleSprite();

		void Reset(float position_x, float position_y);

		void Update(bool move_up_key_pressed,
			bool move_down_key_pressed, TimeService* time_service);

		void Render(RenderWindow* game_window);
	};
}