#include <SDL2/SDL_mixer.h>

#include "audio.h"

void play_soundtrack(char *filename)
{
	Mix_Music *music;
	Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 2048);
	music = Mix_LoadMUS(filename);
	Mix_VolumeMusic(100);
	Mix_PlayMusic(music, -1);
}
