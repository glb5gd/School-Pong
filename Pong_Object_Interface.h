#ifndef OBJECT_INTERFACE_H
#define OBJECT_INTERFACE_H

class Abstract_Object
{
  public:
    Abstract_Object(const string & type, const string & name) : m_type(type), m_name(name){}

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e) = 0;
    virtual void obj_render(SDL_Renderer* const & renderer);

    virtual SDL_Rect get_hitbox() const {}

    virtual string get_type() const;
    virtual string get_name() const;
    virtual long get_state() const;

    virtual bool state_changed(const long & from, const long & to);

    virtual ~Abstract_Object(){}

  protected:
    string m_name{"Abstract Object"};
    string m_type{"Abstract Object"};
    
    long m_prev_state{0};
    long m_next_state{0};
    long m_state{0};
};

class Game_Object : public Abstract_Object
{
  public:
    Game_Object(const string & type, const string & name) : Abstract_Object(type, name){}
    Game_Object(const string & type, const string & name, const SDL_Rect & hitbox) : Abstract_Object(type, name), m_hitbox(hitbox){}

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e) = 0;
    virtual void obj_render(SDL_Renderer* const & renderer);

    virtual ~Game_Object();

    virtual SDL_Rect get_hitbox() const;

    virtual bool check_collision(const SDL_Rect & b) const;

  protected:
    LTexture* m_texture{nullptr};
    SDL_Rect m_hitbox{SDL_Rect{0, 0, 1, 1}};
    double m_x{0};
    double m_y{0};
    double m_v{0};
    double m_angle{0};
    double m_vx{0};
    double m_vy{0};
};

#endif