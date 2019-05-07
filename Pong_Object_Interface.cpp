#include "Pong_Main.h"

void Abstract_Object::obj_render(SDL_Renderer* const & renderer)
{
  m_prev_state = m_state;
  if(m_next_state != m_state)
  {
    m_state = m_next_state;
  }
}

string Abstract_Object::get_type() const
{
  return m_type;
}

string Abstract_Object::get_name() const
{
  return m_name;
}

long Abstract_Object::get_state() const
{
  return m_state;
}

bool Abstract_Object::state_changed(const long & from, const long & to)
{
  if(m_prev_state == from && m_state == to)
  {
    return true;
  }
  return false;
}

void Game_Object::obj_render(SDL_Renderer* const & renderer)
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

Game_Object::~Game_Object()
{
  delete m_texture;
  m_texture = nullptr;
}

SDL_Rect Game_Object::get_hitbox() const
{
  return m_hitbox;
}

bool Game_Object::check_collision(const SDL_Rect & b) const
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