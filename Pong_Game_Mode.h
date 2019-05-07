#ifndef GAME_MODE_H
#define GAME_MODE_H

class Game_Mode : public Abstract_Object
{
  public:
    virtual ~Game_Mode(){}

    Game_Mode(const long & state);

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e){}
};

#endif