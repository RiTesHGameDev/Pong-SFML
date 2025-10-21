#include <iostream>
#include "../../Header/Sounds/SoundManager.h"

namespace Sounds
{
	Music SoundManager::background_music;
	SoundBuffer SoundManager::ball_bounce;
	Sound SoundManager::sound_effect;

	const string SoundManager::bgm_path = "Assets/Sounds/Pong_bgm.mp3";
	const string SoundManager::ball_bounce_path = "Assets/Sounds/Ball_Bounce.wav";

	float SoundManager::background_music_volume = 40.0f;

	void SoundManager::Initialize()
	{
		LoadSoundFromFile();
	}
	void SoundManager::LoadSoundFromFile()
	{
		if (!ball_bounce.loadFromFile(ball_bounce_path))
		{
			cerr << "Error loading sound file" << ball_bounce_path << endl;
		}
		if (!background_music.openFromFile(bgm_path))
		{
			cerr << "Error loading backgrounf music file" << bgm_path << endl;
		}
	}
	void SoundManager::PlaySoundEffect(SoundType sound_type)
	{
		switch (sound_type)
		{
		case SoundType::BALL_BOUNCE:
			sound_effect.setBuffer(ball_bounce);
			break;
		default:
			cerr << "Invalid sound type" << endl;
			return;
		}
		sound_effect.play();
	}
	void SoundManager::PlayBackgroundMusic()
	{
		background_music.setVolume(background_music_volume);
		background_music.setLoop(true);
		background_music.play();
	}
}