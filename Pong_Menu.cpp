#include "Pong_Main.h"

Menu::Menu(SDL_Renderer* const & renderer) : Game_Object("Menu", "Menu")
{
  #include "Pong_Images\\Pong_Menu_Img.h"
  m_texture = new LTexture;
  m_texture->load_from_memory(renderer, MENU_IMG, sizeof(MENU_IMG));
  m_hitbox.w = m_texture->get_width();
  m_hitbox.h = m_texture->get_height();
}