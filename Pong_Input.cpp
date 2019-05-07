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
  if(e.type == SDL_JOYBUTTONDOWN)
  {
    if(e.jbutton.which == 0)
    {
      if(e.jbutton.button == 2)
      {
        m_next_state = 1;
      }
    }
  }
  if(e.type == SDL_KEYUP)
  {
    if(e.key.keysym.sym == SDLK_SPACE)
    {
      m_next_state = 0;
    }
  }
  if(e.type == SDL_JOYBUTTONUP)
  {
    if(e.jbutton.which == 0)
    {
      if(e.jbutton.button == 2)
      {
        m_next_state = 0;
      }
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
  if(e.type == SDL_JOYAXISMOTION)
  {
    //Motion on controller 0
    if(e.jaxis.which == 0)
    {                        
      //Y axis motion
      if(e.jaxis.axis == 1)
      {
        //Above the dead zone
        if(e.jaxis.value < -JOYSTICK_DEAD_ZONE)
        {
          m_next_state = 1;
        }
        else
        {
          m_next_state = 0;
        }
      }
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
  if(e.type == SDL_JOYAXISMOTION)
  {
    //Motion on controller 0
    if(e.jaxis.which == 0)
    {                        
      //Y axis motion
      if(e.jaxis.axis == 1)
      {
        //Below the dead zone
        if(e.jaxis.value > JOYSTICK_DEAD_ZONE)
        {
          m_next_state = 1;
        }
        else
        {
          m_next_state = 0;
        }
      }
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

void Key_Escape::obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
{
  if(e.type == SDL_KEYDOWN)
  {
    if(e.key.keysym.sym == SDLK_ESCAPE)
    {
      for(long j{0}; j < obj_list.size(); ++j)
      {
        if(obj_list[j]->get_type() != "Input" && obj_list[j]->get_type() != "Sound")
        {
          delete obj_list[j];
          obj_list[j] = nullptr;
          obj_list.erase(obj_list.begin() + j);
          --j;
        }
      }
      obj_list.push_back(new Title(renderer));
    }
  }
}