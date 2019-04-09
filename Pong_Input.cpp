#include "Pong_Main.h"

void Key_Space::obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
{
  if(e.type == SDL_KEYDOWN)
  {
    if(e.key.keysym.sym == SDLK_SPACE)
    {
      m_next_state = 1;
    }
  }
  if(e.type == SDL_KEYUP)
  {
    if(e.key.keysym.sym == SDLK_SPACE)
    {
      m_next_state = 0;
    }
  }
}

void Key_Up::obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
{
  if(e.type == SDL_KEYDOWN)
  {
    if(e.key.keysym.sym == SDLK_UP)
    {
      m_next_state = 1;
    }
  }
  if(e.type == SDL_KEYUP)
  {
    if(e.key.keysym.sym == SDLK_UP)
    {
      m_next_state = 0;
    }
  }
}

void Key_Down::obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
{
  if(e.type == SDL_KEYDOWN)
  {
    if(e.key.keysym.sym == SDLK_DOWN)
    {
      m_next_state = 1;
    }
  }
  if(e.type == SDL_KEYUP)
  {
    if(e.key.keysym.sym == SDLK_DOWN)
    {
      m_next_state = 0;
    }
  }
}

void Key_W::obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
{
  if(e.type == SDL_KEYDOWN)
  {
    if(e.key.keysym.sym == SDLK_w)
    {
      m_next_state = 1;
    }
  }
  if(e.type == SDL_KEYUP)
  {
    if(e.key.keysym.sym == SDLK_w)
    {
      m_next_state = 0;
    }
  }
}

void Key_S::obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
{
  if(e.type == SDL_KEYDOWN)
  {
    if(e.key.keysym.sym == SDLK_s)
    {
      m_next_state = 1;
    }
  }
  if(e.type == SDL_KEYUP)
  {
    if(e.key.keysym.sym == SDLK_s)
    {
          m_next_state = 0;
    }
  }
}