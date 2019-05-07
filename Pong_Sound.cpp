#include "Pong_Main.h"

Sound::~Sound()
{
  Mix_FreeChunk(m_sound);
  m_sound = nullptr;
}

Sound::Sound(const string & name, const string & file_name) : Abstract_Object("Sound", name)
{
  //Load sound effects
  m_sound = Mix_LoadWAV(file_name.c_str());
  if(m_sound == nullptr)
  {
    printf("Failed to load a sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    SDL_Delay(2000);
    exit(1);
  }
}

void Sound::obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
{
  Mix_PlayChannel(-1, m_sound, 0);
}