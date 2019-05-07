#include "Pong_Main.h"

Wall2::Wall2(const string & name, SDL_Renderer* const & renderer, const SDL_Point & position) : Game_Object("Wall", name)
{
  #include "Pong_Images\\Pong_Wall2_Img.h"
  m_texture = new LTexture;
  m_texture->load_from_memory(renderer, WALL2_IMG, sizeof(WALL2_IMG));
  m_hitbox = SDL_Rect{position.x, position.y, 3, 256};
  m_x = m_hitbox.x - 4;
  m_y = m_hitbox.y;
}