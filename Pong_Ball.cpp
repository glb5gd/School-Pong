#include "Pong_Main.h"

Box::Box(const string & name, SDL_Renderer* const & renderer, const double & initial_velocity) : Game_Object("Ball", name)
{
  #include "Pong_Images\\Pong_Ball_Img.h"
  m_texture = new LTexture;
  m_texture->load_from_memory(renderer, BOX_IMG, sizeof(BOX_IMG));
  m_hitbox.w = m_texture->get_width();
  m_hitbox.h = m_texture->get_height();
  m_hitbox.x = SCREEN_WIDTH / 2 -  m_hitbox.w / 2;
  m_hitbox.y = SCREEN_HEIGHT / 2 - m_hitbox.h / 2;
  m_x = m_hitbox.x;
  m_y = m_hitbox.y;
  m_v = initial_velocity;
  do
  {
    m_angle = rand() % 360;
    m_vy = m_v * sin(m_angle);
    m_vx = m_v * cos(m_angle);
  } while(abs(m_vx) <= 3 || abs(m_vy) <= 3);
}

void Box::obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
{
  //Move the box up or down
  m_y += m_vy;
  m_hitbox.y = m_y + .5;

  for(long i{0}; i < obj_list.size(); ++i)
  {
    if(obj_list[i]->get_type() == "Screen Edge")
    {
      if(check_collision(obj_list[i]->get_hitbox()) == true)
      {
        if(obj_list[i]->get_name() == "Top" || obj_list[i]->get_name() == "Bottom")
        {
          m_y -= m_vy;
          m_hitbox.y = m_y + .5;
          m_vy = -m_vy;
        }
      }
    }
  }

  //Move the box left or right
  m_x += m_vx;
  m_hitbox.x = m_x + .5;

  for(long i{0}; i < obj_list.size(); ++i)
  {
    if(obj_list[i]->get_type() == "Paddle" || obj_list[i]->get_type() == "Wall")
    {
      if(check_collision(obj_list[i]->get_hitbox()) == true)
      {
        m_x -= m_vx;
        m_hitbox.x = m_x + .5;
        m_vx = -m_vx;
      }
    }
  }

  for(long i{0}; i < obj_list.size(); ++i)
  {
    if(obj_list[i]->get_type() == "Screen Edge")
    {
      if(obj_list[i]->get_name() == "Left" || obj_list[i]->get_name() == "Right")
      {
        if(obj_list[i]->get_state() == 1)
        {
          for(long j{0}; j < obj_list.size(); ++j)
          {
            if(obj_list[j]->get_type() == "Ball")
            {
              if(obj_list[j]->get_name() == "Ball")
              {
                delete obj_list[j];
                obj_list[j] = nullptr;
                obj_list.erase(obj_list.begin() + j);
                --j;
                i = 0;
                obj_list.push_back(new Timer(120));
              }
            }
          }
        }
      }
    }
  }
}