#include "Pong_Main.h"

void Screen_Edge::obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
{
  for(long j{0}; j < obj_list.size(); ++j)
  {
    if(obj_list[j]->get_type() == "Ball")
    {
      if(obj_list[j]->get_name() == "Ball")
      {
        if(check_collision(obj_list[j]->get_hitbox()) == true)
        {
          m_next_state = 1;
        }
      }
    }
    if(obj_list[j]->get_type() == "Timer")
    {
      if(obj_list[j]->get_name() == "Timer")
      {
        if(obj_list[j]->state_changed(5, 4) == true)
        {
          m_next_state = 0;
        }
      }
    }
  }
  if((m_name == "Top" || m_name == "Bottom") && m_state == 1)
  {
    m_next_state = 0;
  }
}