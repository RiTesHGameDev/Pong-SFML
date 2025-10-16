#include "../../Header/Gameplay/Paddle.h"

using namespace sf;

namespace Gameplay
{
	Paddle::Paddle(float position_x, float position_y)
	{
		LoadTexture();
		CreatePaddles(position_x,position_y);
	}
	void Paddle::Update(bool move_up_key_pressed,
		bool move_down_key_pressed)
	{
		PaddleMove(move_up_key_pressed, move_down_key_pressed);
	}
	void Paddle::Render(RenderWindow* game_window)
	{
		game_window->draw(paddle_sprite);
	}
	void Paddle::PaddleMove(bool move_up_key_pressed, bool move_down_key_pressed)
	{
		if (move_up_key_pressed && paddle_sprite.getPosition().y > top_boundary)
		{
			paddle_sprite.move(0,-paddle_speed);
		}
		if (move_down_key_pressed && paddle_sprite.getPosition().y < bottom_boundary)
		{
			paddle_sprite.move(0, paddle_speed);
		}
	}
	void Paddle::LoadTexture()
	{
		if (!paddle_texture.loadFromFile(texture_path))
		{
			throw runtime_error("Failed to load ball texture!");
		}
		paddle_texture.setSmooth(true);
	}
	void Paddle::CreatePaddles(float position_x, float position_y)
	{
		paddle_sprite.setTexture(paddle_texture);
		paddle_sprite.setScale(scale_x, scale_y);
		paddle_sprite.setPosition(position_x, position_y);
	}
	Sprite Paddle::GetPaddleSprite()
	{
		return paddle_sprite;
	}
	void Paddle::Reset(float positon_x,float position_y)
	{
		paddle_sprite.setPosition(positon_x,position_y);
	}
}