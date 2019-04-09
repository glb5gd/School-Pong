#ifndef SCORE_GRAPHIC_H
#define SCORE_GRAPHIC_H

class Score_Graphic : public Game_Object
{
  public:
    virtual ~Score_Graphic(){}

    Score_Graphic(const string & name, const SDL_Point & position, SDL_Renderer* const & renderer, vector<Abstract_Object*> & obj_list);

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e){}
};
  
#endif