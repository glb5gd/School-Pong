#include "Pong_Main.h"

Timer::Timer(const long & frames) : Abstract_Object("Timer", "Timer")
{
  m_state = frames;
  m_next_state = frames;
}

void Timer::obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
{
  --m_next_state;
}