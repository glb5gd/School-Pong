#ifndef INPUT_H
#define INPUT_H

class Key_Space : public Abstract_Object
{
  public:
    virtual ~Key_Space(){}

    Key_Space() : Abstract_Object("Input", "Space"){}

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);
};

class Key_Up : public Abstract_Object
{
  public:
    virtual ~Key_Up(){}

    Key_Up() : Abstract_Object("Input", "Up"){}

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);
};

class Key_Down : public Abstract_Object
{
  public:
    virtual ~Key_Down(){}

    Key_Down() : Abstract_Object("Input", "Down"){}

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);
};

class Key_W : public Abstract_Object
{
  public:
    virtual ~Key_W(){}

    Key_W() : Abstract_Object("Input", "W"){}

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);
};

class Key_S : public Abstract_Object
{
  public:
    virtual ~Key_S(){}

    Key_S() : Abstract_Object("Input", "S"){}

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);
};

class Key_Escape : public Abstract_Object
{
  public:
    virtual ~Key_Escape(){}

    Key_Escape() : Abstract_Object("Input", "Escape"){}

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e);
};

#endif