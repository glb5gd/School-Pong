#ifndef TIMER_H
#define TIMER_H

class Timer : public Abstract_Object
{
  public:
    virtual ~Timer(){}

    Timer(const long & frames);

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);
};

#endif