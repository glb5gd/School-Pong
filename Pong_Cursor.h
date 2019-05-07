#ifndef CURSOR_H
#define CURSOR_H

class Cursor : public Game_Object
{
  public:
    virtual ~Cursor(){}

    Cursor(const string & name, SDL_Renderer* const & renderer);

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);
};
  
#endif