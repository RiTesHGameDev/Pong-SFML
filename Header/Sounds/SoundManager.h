#pragma once
#include <SFML/Audio.hpp>
#include <string>

using namespace sf;
using namespace std;

namespace Sounds
{
	enum class SoundType
	{
		BALL_BOUNCE
	};
	class SoundManager
	{
	private:
		static Music background_music;
		static Sound sound_effect;
		static SoundBuffer ball_bounce;

		static float background_music_volume;
		static const string bgm_path;
		static const string ball_bounce_path;

		
		static void LoadSoundFromFile();

	public:
		static void Initialize();
		static void PlaySoundEffect(SoundType sound_type);
		static void PlayBackgroundMusic();
	};
}