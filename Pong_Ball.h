#ifndef BOX_H
#define BOX_H

const long BOX_INITIAL_VELOCITY{5};

class Box : public Game_Object
{
  public:
    virtual ~Box(){}

    Box(const string & name, SDL_Renderer* const & renderer) : Game_Object("Box", name)
    {
      #include "Pong_Ball_Img.h"
      m_texture = new LTexture;
      m_texture->load_from_memory(renderer, BOX_IMG, sizeof(BOX_IMG));
      m_hitbox.w = m_texture->get_width();
      m_hitbox.h = m_texture->get_height();
      m_hitbox.x = SCREEN_WIDTH / 2 -  m_hitbox.w / 2;
      m_hitbox.y = SCREEN_HEIGHT / 2 - m_hitbox.h / 2;
      m_x = m_hitbox.x;
      m_y = m_hitbox.y;
      m_v = BOX_INITIAL_VELOCITY;
      m_angle = rand() % 360;
      m_vx = m_v * cos(m_angle);
      m_vy = m_v * sin(m_angle);
    }

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
    {
      //Move the box left or right
      m_x += m_vx;
      m_hitbox.x = m_x + .5;

      for(long i{0}; i < obj_list.size(); ++i)
      {
        if(obj_list[i]->get_type() == "Screen Edge")
        {
          if(check_collision(obj_list[i]->get_hitbox()) == true)
          {
            m_x -= m_vx;
            m_hitbox.x = m_x + .5;
            m_vx = -m_vx;
          }
        }
      }

      //Move the box up or down
      m_y += m_vy;
      m_hitbox.y = m_y + .5;

      for(long i{0}; i < obj_list.size(); ++i)
      {
        if(obj_list[i]->get_type() == "Screen Edge")
        {
          if(check_collision(obj_list[i]->get_hitbox()) == true)
          {
            m_y -= m_vy;
            m_hitbox.y = m_y + .5;
            m_vy = -m_vy;
          }
        }
      }
    }
};
  
#endif