#ifndef SCREEN_EDGE_H
#define SCREEN_EDGE_H

class Screen_Edge : public Game_Object
{
  public:
    virtual ~Screen_Edge(){}

    Screen_Edge(const string & name, const SDL_Rect & hitbox) : Game_Object("Screen Edge", name, hitbox){}

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);
};

#endif