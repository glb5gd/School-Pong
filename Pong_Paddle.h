#ifndef PADDLE_H
#define PADDLE_H

const long PADDLE_VELOCITY{5};

class Paddle : public Game_Object
{
  public:
    virtual ~Paddle(){}

    Paddle(const string & name, SDL_Renderer* const & renderer, const SDL_Rect & hitbox) : Game_Object("Paddle", name, hitbox)
    {
      #include "Pong_Paddle_Img.h"
      m_texture = new LTexture;
      m_texture->load_from_memory(renderer, PADDLE_IMG, sizeof(PADDLE_IMG));
      m_x = m_hitbox.x - 8;
      m_y = m_hitbox.y;
    }

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
    {
      //Move Player 1's paddle
      if(m_name == "P1")
      {
        for(long i{0}; i < obj_list.size(); ++i)
        {
          if(obj_list[i]->get_type() == "Input")
          {
            if(obj_list[i]->get_name() == "W")
            {
              if(obj_list[i]->get_state() == 1)
              {
                m_vy = -5;
              }
              if(obj_list[i]->state_changed(1, 0) == true)
              {
                m_vy = 0;
              }
            }
            if(obj_list[i]->get_name() == "S")
            {
              if(obj_list[i]->get_state() == 1)
              {
                m_vy = 5;
              }
              if(obj_list[i]->state_changed(1, 0) == true)
              {
                m_vy = 0;
              }
            }
          }
        }
      }
      else
      {
        for(long i{0}; i < obj_list.size(); ++i)
        {
          if(obj_list[i]->get_type() == "Input")
          {
            if(obj_list[i]->get_name() == "Up")
            {
              if(obj_list[i]->get_state() == 1)
              {
                m_vy = -5;
              }
              if(obj_list[i]->state_changed(1, 0) == true)
              {
                m_vy = 0;
              }
            }
            if(obj_list[i]->get_name() == "Down")
            {
              if(obj_list[i]->get_state() == 1)
              {
                m_vy = 5;
              }
              if(obj_list[i]->state_changed(1, 0) == true)
              {
                m_vy = 0;
              }
            }
          }
        }
      }
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
          }
        }
      }
    }
};
  
#endif