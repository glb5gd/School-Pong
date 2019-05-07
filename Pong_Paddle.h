#ifndef PADDLE_H
#define PADDLE_H

class Paddle : public Game_Object
{
  public:
    virtual ~Paddle(){}

    Paddle(const string & name, SDL_Renderer* const & renderer, const SDL_Rect & hitbox);

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);
};
  
#endif