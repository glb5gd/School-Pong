#include "Pong_Main.h"

Wall::Wall(const string & name, SDL_Renderer* const & renderer, const SDL_Point & position) : Game_Object("Wall", name)
{
  #include "Pong_Images\\Pong_Wall_Img.h"
  m_texture = new LTexture;
  m_texture->load_from_memory(renderer, WALL_IMG, sizeof(WALL_IMG));
  m_hitbox = SDL_Rect{position.x, position.y, 3, 128};
  m_x = m_hitbox.x - 4;
  m_y = m_hitbox.y;
}