#ifndef TITLE_H
#define TITLE_H

class Title : public Game_Object
{
  public:
    virtual ~Title(){}

    Title(SDL_Renderer* const & renderer) : Game_Object("Title", "Title")
    {
      #include "Pong_Title_Img.h"
      m_texture = new LTexture;
      m_texture->load_from_memory(renderer, TITLE_IMG, sizeof(TITLE_IMG));
      m_hitbox.w = m_texture->get_width();
      m_hitbox.h = m_texture->get_height();
    }

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
    {
      for(long i{0}; i < obj_list.size(); ++i)
      {
        if(obj_list[i]->get_type() == "Input")
        {
          if(obj_list[i]->get_name() == "Space")
          {
            if(obj_list[i]->state_changed(0, 1) == true)
            {
              obj_list.push_back(new Menu(renderer));
              obj_list.push_back(new Cursor("Cursor", renderer));
              for(long j{0}; j < obj_list.size(); ++j)
              {
                if(obj_list[j]->get_type() == "Title")
                {
                  if(obj_list[j]->get_name() == "Title")
                  {
                    delete obj_list[j];
                    obj_list[j] = nullptr;
                    obj_list.erase(obj_list.begin() + j);
                    j--;
                  }
                }
              }
            }
          }
        }
      }
    }
};
  
#endif