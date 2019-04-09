#include "Pong_Main.h"

Win_Graphic::Win_Graphic(const string & name, SDL_Renderer* const & renderer) : Game_Object("Win Graphic", name)
{
  m_hitbox.x = 100;
  m_hitbox.y = 100;
  m_x = m_hitbox.x;
  m_y = m_hitbox.y;

  if(m_name == "P1")
  {
    #include "Pong_Images\\Pong_P1win_Img.h"
    m_texture = new LTexture;
    m_texture->load_from_memory(renderer, WIN_IMG, sizeof(WIN_IMG));
  }
  else
  {
    #include "Pong_Images\\Pong_P2win_Img.h"
    m_texture = new LTexture;
    m_texture->load_from_memory(renderer, WIN_IMG, sizeof(WIN_IMG));
  }
  m_hitbox.w = m_texture->get_width();
  m_hitbox.h = m_texture->get_height();
}

void Win_Graphic::obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
{
  for(long i{0}; i < obj_list.size(); ++i)
  {
    if(obj_list[i]->get_type() == "Timer")
    {
      if(obj_list[i]->get_name() == "Timer")
      {
        if(obj_list[i]->state_changed(1, 0) == true)
        {
          for(long j{0}; j < obj_list.size(); ++j)
          {
            if(obj_list[j]->get_type() != "Input")
            {
              delete obj_list[j];
              obj_list[j] = nullptr;
              obj_list.erase(obj_list.begin() + j);
              --j;
              i = 0;
            }
          }
          obj_list.push_back(new Menu(renderer));
          obj_list.push_back(new Cursor("Cursor", renderer));
        }
      }
    }
  }
}