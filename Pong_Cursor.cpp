#include "Pong_Main.h"

Cursor::Cursor(const string & name, SDL_Renderer* const & renderer) : Game_Object("Cursor", name)
{
  #include "Pong_Images\\Pong_Cursor_Img.h"
  m_texture = new LTexture;
  m_texture->load_from_memory(renderer, CURSOR_IMG, sizeof(CURSOR_IMG));
  m_hitbox.w = m_texture->get_width();
  m_hitbox.h = m_texture->get_height();
  m_hitbox.x = 58;
  m_hitbox.y = 18;
  m_x = m_hitbox.x;
  m_y = m_hitbox.y;
}

void Cursor::obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
{
  for(long i{0}; i < obj_list.size(); ++i)
  {
    if(obj_list[i]->get_type() == "Input")
    {
      if(obj_list[i]->get_name() == "Down")
      {
        if(obj_list[i]->state_changed(0, 1) == true)
        {
          if(m_state == 0)
          {
            m_next_state = 1;
          }
          else
          {
            m_next_state = m_state + 1;
            if(m_next_state == 6)
            {
              m_next_state = 1;
            }
          }
        }
      }
      if(obj_list[i]->get_name() == "Up")
      {
        if(obj_list[i]->state_changed(0, 1) == true)
        {
          if(m_state == 0)
          {
            m_next_state = 1;
          }
          else
          {
            m_next_state = m_state - 1;
            if(m_next_state == 0)
            {
              m_next_state = 5;
            }
          }
        }
      }
    }
  }
  m_hitbox.y = 18 + 54 * (m_state - 1);
  m_y = m_hitbox.y;

  for(long i{0}; i < obj_list.size(); ++i)
  {
    if(obj_list[i]->get_type() == "Input")
    {
      if(obj_list[i]->get_name() == "Space")
      {
        if(obj_list[i]->state_changed(0, 1) == true)
        {
          switch(m_state)
          {
            case 1:
              obj_list.push_back(new Screen_Edge("Left", SDL_Rect{0, 0, 3, SCREEN_HEIGHT}));
              obj_list.push_back(new Screen_Edge("Right", SDL_Rect{SCREEN_WIDTH, 0, 3, SCREEN_HEIGHT}));
              obj_list.push_back(new Screen_Edge("Top", SDL_Rect{0, 0, SCREEN_WIDTH, 3}));
              obj_list.push_back(new Screen_Edge("Bottom", SDL_Rect{0, SCREEN_HEIGHT, SCREEN_WIDTH, 3}));
              obj_list.push_back(new Box("Ball", renderer, 5));
              obj_list.push_back(new Paddle("P1", renderer, SDL_Rect{32, SCREEN_HEIGHT / 2, 3, 64}));
              obj_list.push_back(new Paddle("P2", renderer, SDL_Rect{SCREEN_WIDTH - 32, SCREEN_HEIGHT / 2, 3, 64}));
              obj_list.push_back(new P1Score("P1"));
              obj_list.push_back(new P2Score("P2"));
              obj_list.push_back(new Game_Mode(1));
              for(long j{0}; j < obj_list.size(); ++j)
              {
                if(obj_list[j]->get_type() == "Menu")
                {
                  if(obj_list[j]->get_name() == "Menu")
                  {
                    delete obj_list[j];
                    obj_list[j] = nullptr;
                    obj_list.erase(obj_list.begin() + j);
                    --j;
                    i = 0;
                  }
                }
                if(obj_list[j]->get_type() == "Cursor")
                {
                  if(obj_list[j]->get_name() == "Cursor")
                  {
                    delete obj_list[j];
                    obj_list[j] = nullptr;
                    obj_list.erase(obj_list.begin() + j);
                    --j;
                    i = 0;
                  }
                }
              }
              break;

            case 2:
              obj_list.push_back(new Screen_Edge("Left", SDL_Rect{0, 0, 3, SCREEN_HEIGHT}));
              obj_list.push_back(new Screen_Edge("Right", SDL_Rect{SCREEN_WIDTH, 0, 3, SCREEN_HEIGHT}));
              obj_list.push_back(new Screen_Edge("Top", SDL_Rect{0, 0, SCREEN_WIDTH, 3}));
              obj_list.push_back(new Screen_Edge("Bottom", SDL_Rect{0, SCREEN_HEIGHT, SCREEN_WIDTH, 3}));
              obj_list.push_back(new Box("Ball", renderer, 7));
              obj_list.push_back(new Paddle("P1", renderer, SDL_Rect{32, SCREEN_HEIGHT / 2, 3, 64}));
              obj_list.push_back(new Paddle("P2", renderer, SDL_Rect{SCREEN_WIDTH - 32, SCREEN_HEIGHT / 2, 3, 64}));
              obj_list.push_back(new P1Score("P1"));
              obj_list.push_back(new P2Score("P2"));
              obj_list.push_back(new Game_Mode(2));
              for(long j{0}; j < obj_list.size(); ++j)
              {
                if(obj_list[j]->get_type() == "Menu")
                {
                  if(obj_list[j]->get_name() == "Menu")
                  {
                    delete obj_list[j];
                    obj_list[j] = nullptr;
                    obj_list.erase(obj_list.begin() + j);
                    --j;
                    i = 0;
                  }
                }
                if(obj_list[j]->get_type() == "Cursor")
                {
                  if(obj_list[j]->get_name() == "Cursor")
                  {
                    delete obj_list[j];
                    obj_list[j] = nullptr;
                    obj_list.erase(obj_list.begin() + j);
                    --j;
                    i = 0;
                  }
                }
              }
              break;

            case 3:
              obj_list.push_back(new Screen_Edge("Left", SDL_Rect{0, 0, 3, SCREEN_HEIGHT}));
              obj_list.push_back(new Screen_Edge("Right", SDL_Rect{SCREEN_WIDTH, 0, 3, SCREEN_HEIGHT}));
              obj_list.push_back(new Screen_Edge("Top", SDL_Rect{0, 0, SCREEN_WIDTH, 3}));
              obj_list.push_back(new Screen_Edge("Bottom", SDL_Rect{0, SCREEN_HEIGHT, SCREEN_WIDTH, 3}));
              obj_list.push_back(new Box("Ball", renderer, 5));
              obj_list.push_back(new Paddle("P1", renderer, SDL_Rect{32, SCREEN_HEIGHT / 2, 3, 64}));
              obj_list.push_back(new Paddle("P2", renderer, SDL_Rect{SCREEN_WIDTH - 32, SCREEN_HEIGHT / 2, 3, 64}));
              obj_list.push_back(new P1Score("P1"));
              obj_list.push_back(new P2Score("P2"));
              obj_list.push_back(new Wall("1", renderer, SDL_Point{SCREEN_WIDTH / 2 - 4, 0}));
              obj_list.push_back(new Wall("2", renderer, SDL_Point{SCREEN_WIDTH / 2 - 4, SCREEN_HEIGHT - 128}));
              obj_list.push_back(new Game_Mode(3));
              for(long j{0}; j < obj_list.size(); ++j)
              {
                if(obj_list[j]->get_type() == "Menu")
                {
                  if(obj_list[j]->get_name() == "Menu")
                  {
                    delete obj_list[j];
                    obj_list[j] = nullptr;
                    obj_list.erase(obj_list.begin() + j);
                    --j;
                    i = 0;
                  }
                }
                if(obj_list[j]->get_type() == "Cursor")
                {
                  if(obj_list[j]->get_name() == "Cursor")
                  {
                    delete obj_list[j];
                    obj_list[j] = nullptr;
                    obj_list.erase(obj_list.begin() + j);
                    --j;
                    i = 0;
                  }
                }
              }
              break;

            case 4:
              obj_list.push_back(new Screen_Edge("Left", SDL_Rect{0, 0, 3, SCREEN_HEIGHT}));
              obj_list.push_back(new Screen_Edge("Right", SDL_Rect{SCREEN_WIDTH, 0, 3, SCREEN_HEIGHT}));
              obj_list.push_back(new Screen_Edge("Top", SDL_Rect{0, 0, SCREEN_WIDTH, 3}));
              obj_list.push_back(new Screen_Edge("Bottom", SDL_Rect{0, SCREEN_HEIGHT, SCREEN_WIDTH, 3}));
              obj_list.push_back(new Box("Ball", renderer, 5));
              obj_list.push_back(new Paddle("P1", renderer, SDL_Rect{32, SCREEN_HEIGHT / 2, 3, 64}));
              obj_list.push_back(new Paddle("P2", renderer, SDL_Rect{SCREEN_WIDTH - 32, SCREEN_HEIGHT / 2, 3, 64}));
              obj_list.push_back(new P1Score("P1"));
              obj_list.push_back(new P2Score("P2"));
              obj_list.push_back(new Wall2("1", renderer, SDL_Point{SCREEN_WIDTH / 2 - 4, 112}));
              obj_list.push_back(new Game_Mode(4));
              for(long j{0}; j < obj_list.size(); ++j)
              {
                if(obj_list[j]->get_type() == "Menu")
                {
                  if(obj_list[j]->get_name() == "Menu")
                  {
                    delete obj_list[j];
                    obj_list[j] = nullptr;
                    obj_list.erase(obj_list.begin() + j);
                    --j;
                    i = 0;
                  }
                }
                if(obj_list[j]->get_type() == "Cursor")
                {
                  if(obj_list[j]->get_name() == "Cursor")
                  {
                    delete obj_list[j];
                    obj_list[j] = nullptr;
                    obj_list.erase(obj_list.begin() + j);
                    --j;
                    i = 0;
                  }
                }
              }
              break;

            case 5:
              obj_list.push_back(new Screen_Edge("Left", SDL_Rect{0, 0, 3, SCREEN_HEIGHT}));
              obj_list.push_back(new Screen_Edge("Right", SDL_Rect{SCREEN_WIDTH, 0, 3, SCREEN_HEIGHT}));
              obj_list.push_back(new Screen_Edge("Top", SDL_Rect{0, 0, SCREEN_WIDTH, 3}));
              obj_list.push_back(new Screen_Edge("Bottom", SDL_Rect{0, SCREEN_HEIGHT, SCREEN_WIDTH, 3}));
              obj_list.push_back(new Box("Ball", renderer, 5));
              obj_list.push_back(new Box("Ball", renderer, 5));
              obj_list.push_back(new Paddle("P1", renderer, SDL_Rect{32, SCREEN_HEIGHT / 2, 3, 64}));
              obj_list.push_back(new Paddle("P2", renderer, SDL_Rect{SCREEN_WIDTH - 32, SCREEN_HEIGHT / 2, 3, 64}));
              obj_list.push_back(new P1Score("P1"));
              obj_list.push_back(new P2Score("P2"));
              obj_list.push_back(new Game_Mode(5));
              for(long j{0}; j < obj_list.size(); ++j)
              {
                if(obj_list[j]->get_type() == "Menu")
                {
                  if(obj_list[j]->get_name() == "Menu")
                  {
                    delete obj_list[j];
                    obj_list[j] = nullptr;
                    obj_list.erase(obj_list.begin() + j);
                    --j;
                    i = 0;
                  }
                }
                if(obj_list[j]->get_type() == "Cursor")
                {
                  if(obj_list[j]->get_name() == "Cursor")
                  {
                    delete obj_list[j];
                    obj_list[j] = nullptr;
                    obj_list.erase(obj_list.begin() + j);
                    --j;
                    i = 0;
                  }
                }
              }
              break;

            default:
              break;
          }
        }
      }
    }
  }
}