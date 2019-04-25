#include "Pong_Main.h"

void P1Score::obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
{
  for(long i{0}; i < obj_list.size(); ++i)
  {
    if(obj_list[i]->get_type() == "Screen Edge")
    {
      if(obj_list[i]->get_name() == "Right")
      {
        if(obj_list[i]->state_changed(0, 1) == true)
        {
          ++m_next_state;
        }
      }
    }
  }
  for(long i{0}; i < obj_list.size(); ++i)
  {
    if(obj_list[i]->get_type() == "Timer")
    {
      if(obj_list[i]->get_name() == "Timer")
      {
        if(obj_list[i]->state_changed(115, 114) == true && m_state != 11)
        {
          SDL_Point position{100,100};
          obj_list.push_back(new Score_Graphic(m_name, position, renderer, obj_list));
        }
        if(obj_list[i]->state_changed(1, 0) == true && m_state != 11)
        {
          for(long j{0}; j < obj_list.size(); ++j)
          {
            if(obj_list[j]->get_type() == "Game Mode")
            {
              if(obj_list[j]->get_name() == "Game Mode")
              {
                if(obj_list[j]->get_state() == 2)
                {
                  obj_list.push_back(new Box("Ball", renderer, 7));
                }
                else if(obj_list[j]->get_state() == 5)
                {
                  obj_list.push_back(new Box("Ball", renderer, 5));
                  obj_list.push_back(new Box("Ball", renderer, 5));
                }
                else
                {
                  obj_list.push_back(new Box("Ball", renderer, 5));
                }
              }
            }
          }
          for(long j{0}; j < obj_list.size(); ++j)
          {
            if(obj_list[j]->get_type() == "Timer")
            {
              delete obj_list[j];
              obj_list[j] = nullptr;
              obj_list.erase(obj_list.begin() + j);
              --j;
              i = 0;
            }
            if(obj_list[j]->get_type() == "Score Graphic")
            {
              delete obj_list[j];
              obj_list[j] = nullptr;
              obj_list.erase(obj_list.begin() + j);
              --j;
              i = 0;
            }
          }
        }
        if(obj_list[i]->state_changed(115, 114) == true && m_state == 11)
        {
          obj_list.push_back(new Win_Graphic(m_name, renderer));
          for(long j{0}; j < obj_list.size(); ++j)
          {
            if(obj_list[j]->get_type() != "Timer" && obj_list[j]->get_type() != "Win Graphic" && obj_list[j]->get_type() != "Input" && obj_list[j]->get_type() != "Sound" && obj_list[j]->get_type() != "Game Mode")
            {
              delete obj_list[j];
              obj_list[j] = nullptr;
              obj_list.erase(obj_list.begin() + j);
              --j;
              i = 0;
            }
          }
        }
      }
    }
  }
}