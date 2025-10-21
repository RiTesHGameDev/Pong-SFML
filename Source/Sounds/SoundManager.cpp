#include <iostream>
#include "../../Header/Sounds/SoundManager.h"

namespace Sounds
{
	SoundBuffer SoundManager::ball_bounce;
	Sound SoundManager::sound_effect;

	const string SoundManager::ball_bounce_path = "Assets/Sounds/Ball_Bounce.wav";

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
}