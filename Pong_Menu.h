#ifndef MENU_H
#define MENU_H

class Menu : public Game_Object
{
  public:
    virtual ~Menu(){}

    Menu(SDL_Renderer* const & renderer);

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e){}
};
  
#endif