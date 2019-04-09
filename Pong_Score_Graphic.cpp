#include "Pong_Main.h"

Score_Graphic::Score_Graphic(const string & name, const SDL_Point & position, SDL_Renderer* const & renderer, vector<Abstract_Object*> & obj_list) : Game_Object("Score Graphic", name)
{
  m_hitbox.x = position.x;
  m_hitbox.y = position.y;
  m_x = m_hitbox.x;
  m_y = m_hitbox.y;

  for(long i{0}; i < obj_list.size(); ++i)
  {
    if(obj_list[i]->get_type() == "Score")
    {
      if(obj_list[i]->get_name() == m_name)
      {
        switch(obj_list[i]->get_state())
        {
          case 0:
          {
            #include "Pong_Images\\Pong_Zero_Img.h"
            m_texture = new LTexture;
            m_texture->load_from_memory(renderer, SCORE_IMG, sizeof(SCORE_IMG));
            break;
          }

          case 1:
          {
            #include "Pong_Images\\Pong_One_Img.h"
            m_texture = new LTexture;
            m_texture->load_from_memory(renderer, SCORE_IMG, sizeof(SCORE_IMG));
            break;
          }

          case 2:
          {
            #include "Pong_Images\\Pong_Two_Img.h"
            m_texture = new LTexture;
            m_texture->load_from_memory(renderer, SCORE_IMG, sizeof(SCORE_IMG));
            break;
          }

          case 3:
          {
            #include "Pong_Images\\Pong_Three_Img.h"
            m_texture = new LTexture;
            m_texture->load_from_memory(renderer, SCORE_IMG, sizeof(SCORE_IMG));
            break;
          }

          case 4:
          {
            #include "Pong_Images\\Pong_Four_Img.h"
            m_texture = new LTexture;
            m_texture->load_from_memory(renderer, SCORE_IMG, sizeof(SCORE_IMG));
            break;
          }

          case 5:
          {
            #include "Pong_Images\\Pong_Five_Img.h"
            m_texture = new LTexture;
            m_texture->load_from_memory(renderer, SCORE_IMG, sizeof(SCORE_IMG));
            break;
          }

          case 6:
          {
            #include "Pong_Images\\Pong_Six_Img.h"
            m_texture = new LTexture;
            m_texture->load_from_memory(renderer, SCORE_IMG, sizeof(SCORE_IMG));
            break;
          }

          case 7:
          {
            #include "Pong_Images\\Pong_Seven_Img.h"
            m_texture = new LTexture;
            m_texture->load_from_memory(renderer, SCORE_IMG, sizeof(SCORE_IMG));
            break;
          }

          case 8:
          {
            #include "Pong_Images\\Pong_Eight_Img.h"
            m_texture = new LTexture;
            m_texture->load_from_memory(renderer, SCORE_IMG, sizeof(SCORE_IMG));
            break;
          }

          case 9:
          {
            #include "Pong_Images\\Pong_Nine_Img.h"
            m_texture = new LTexture;
            m_texture->load_from_memory(renderer, SCORE_IMG, sizeof(SCORE_IMG));
            break;
          }

          case 10:
          {
            #include "Pong_Images\\Pong_Ten_Img.h"
            m_texture = new LTexture;
            m_texture->load_from_memory(renderer, SCORE_IMG, sizeof(SCORE_IMG));
            break;
          }

          default:
          {
            #include "Pong_Images\\Pong_Zero_Img2.h"
            m_texture = new LTexture;
            m_texture->load_from_memory(renderer, SCORE_IMG, sizeof(SCORE_IMG));
            break;
          }
        }
      }
    }
  }
  m_hitbox.w = m_texture->get_width();
  m_hitbox.h = m_texture->get_height();
}