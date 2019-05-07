#ifndef BOX_H
#define BOX_H

class Box : public Game_Object
{
  public:
    virtual ~Box(){}

    Box(const string & name, SDL_Renderer* const & renderer, const double & initial_velocity);

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);
};
  
#endif