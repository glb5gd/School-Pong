#ifndef P1SCORE_H
#define P1SCORE_H

class P1Score : public Abstract_Object
{
  public:
    virtual ~P1Score(){}

    P1Score(const string & name) : Abstract_Object("Score", name){}

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);
};

#endif