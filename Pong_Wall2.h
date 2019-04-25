#ifndef WALL2_H
#define WALL2_H

class Wall2 : public Game_Object
{
  public:
    virtual ~Wall2(){}

    Wall2(const string & name, SDL_Renderer* const & renderer, const SDL_Point & position);

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e){}
};
  
#endif