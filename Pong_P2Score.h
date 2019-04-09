#ifndef P2SCORE_H
#define P2SCORE_H

class P2Score : public Abstract_Object
{
  public:
    virtual ~P2Score(){}

    P2Score(const string & name) : Abstract_Object("Score", name){}

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);
};

#endif