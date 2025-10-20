#include "../../Header/Gameplay/Paddle.h"

using namespace sf;

namespace Gameplay
{
	Paddle::Paddle(float position_x, float position_y)
	{
		LoadTexture();
		Initialize(position_x,position_y);
	}
	void Paddle::Update(bool move_up_key_pressed,
		bool move_down_key_pressed, TimeService* time_service)
	{
		PaddleMove(move_up_key_pressed, move_down_key_pressed,time_service);
	}
	void Paddle::Render(RenderWindow* game_window)
	{
		game_window->draw(paddle_sprite);
	}
	void Paddle::PaddleMove(bool move_up_key_pressed, bool move_down_key_pressed,TimeService* time_service)
	{
		if (move_up_key_pressed && paddle_sprite.getPosition().y > top_boundary)
		{
			paddle_sprite.move(0,-paddle_speed * time_service->GetDeltaTime() * speed_multiplier);
		}
		if (move_down_key_pressed && paddle_sprite.getPosition().y < bottom_boundary)
		{
			paddle_sprite.move(0, paddle_speed * time_service->GetDeltaTime() * speed_multiplier);
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
	void Paddle::Initialize(float position_x, float position_y)
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