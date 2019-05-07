#ifndef WALL_H
#define WALL_H

class Wall : public Game_Object
{
  public:
    virtual ~Wall(){}

    Wall(const string & name, SDL_Renderer* const & renderer, const SDL_Point & position);

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e){}
};
  
#endif