#include "../../Header/UI/UIService.h"

namespace UI
{
	UIService::UIService()
	{
		LoadFontTexture();
		CreateLeftScoreText();
		CreateRightScoreText();
	}
	void UIService::LoadFontTexture()
	{
		font.loadFromFile(texture_path);
	}
	void UIService::CreateLeftScoreText()
	{
		left_score_text.setFont(font);
		left_score_text.setString(initial_string);
		left_score_text.setCharacterSize(font_size);
		left_score_text.setFillColor(font_color);
		left_score_text.setPosition(left_score_position_x, left_score_position_y);
	}
	void UIService::CreateRightScoreText()
	{
		right_score_text.setFont(font);
		right_score_text.setString(initial_string);
		right_score_text.setCharacterSize(font_size);
		right_score_text.setFillColor(font_color);
		right_score_text.setPosition(right_score_position_x, right_score_position_y);
	}
	void UIService::Render(RenderWindow* game_window)
	{
		game_window->draw(left_score_text);
		game_window->draw(right_score_text);
	}
	string UIService::FormatScore(int score)
	{
		return(score < 10 ? "0" : "") + to_string(score);
	}
	void UIService::IncrementPlayer1Score()
	{
		player1_score++;
	}
	void UIService::IncrementPlayer2Score()
	{
		player2_score++;
	}
	void UIService::Update()
	{
		left_score_text.setString(FormatScore(player1_score));
		right_score_text.setString(FormatScore(player2_score));
	}
}