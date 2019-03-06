#ifndef INPUT_H
#define INPUT_H

class Key_Space : public Abstract_Object
{
  public:
    virtual ~Key_Space(){}

    Key_Space() : Abstract_Object("Input", "Space"){}

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e)
    {
      if(e.type == SDL_KEYDOWN)
      {
        if(e.key.keysym.sym == SDLK_SPACE)
        {
          m_next_state = 1;
        }
      }
      if(e.type == SDL_KEYUP)
      {
        if(e.key.keysym.sym == SDLK_SPACE)
        {
          m_next_state = 0;
        }
      }
    }
};

#endif