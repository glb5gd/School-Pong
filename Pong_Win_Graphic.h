#ifndef Win_GRAPHIC_H
#define Win_GRAPHIC_H

class Win_Graphic : public Game_Object
{
  public:
    virtual ~Win_Graphic(){}

    Win_Graphic(const string & name, SDL_Renderer* const & renderer);

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);
};
  
#endif