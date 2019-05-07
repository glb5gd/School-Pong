#ifndef TITLE_H
#define TITLE_H

class Title : public Game_Object
{
  public:
    virtual ~Title(){}

    Title(SDL_Renderer* const & renderer);

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);
};
  
#endif