#ifndef OBJECT_INTERFACE_H
#define OBJECT_INTERFACE_H

class Abstract_Object
{
  public:
    Abstract_Object(const string & type, const string & name) : m_type(type), m_name(name){}

    virtual void obj_main(vector<Abstract_Object*> & obj_list, SDL_Renderer* const & renderer, SDL_Event & e) = 0;
    virtual void obj_render(SDL_Renderer* const & renderer)
    {
      m_prev_state = m_state;
      if(m_next_state != m_state)
      {
        m_state = m_next_state;
      }
    }

    virtual SDL_Rect get_hitbox() const {}

    virtual string get_type() const {return m_type;}
    virtual string get_name() const {return m_name;}
    virtual long get_state() const {return m_state;}

    virtual bool state_changed(const long & from, const long & to)
    {
      if(m_prev_state == from && m_state == to)
      {
        return true;
      }
      return false;
    }

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
    virtual void obj_render(SDL_Renderer* const & renderer)
    {
      if(m_texture != nullptr)
      {
        m_texture->render(renderer, m_x, m_y);
      }

      m_prev_state = m_state;
      if(m_next_state != m_state)
      {
        m_state = m_next_state;
      }
    }

    virtual ~Game_Object(){delete m_texture; m_texture = nullptr;}

    virtual SDL_Rect get_hitbox() const {return m_hitbox;}

    virtual bool check_collision(const SDL_Rect & b) const
    {
      long left_A, left_B;
      long right_A, right_B;
      long top_A, top_B;
      long bottom_A, bottom_B;

      left_A = m_hitbox.x;
      right_A = m_hitbox.x + m_hitbox.w;
      top_A = m_hitbox.y;
      bottom_A = m_hitbox.y + m_hitbox.h;

      left_B = b.x;
      right_B = b.x + b.w;
      top_B = b.y;
      bottom_B = b.y + b.h;

      if(bottom_A <= top_B)
      {
        return false;
      }

      if(top_A >= bottom_B)
      {
        return false;
      }

      if(right_A <= left_B)
      {
        return false;
      }

      if(left_A >= right_B)
      {
        return false;
      }
      return true;
    }

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