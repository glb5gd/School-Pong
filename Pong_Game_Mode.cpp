#include "Pong_Main.h"

Game_Mode::Game_Mode(const long & state) : Abstract_Object("Game Mode", "Game Mode")
{
  m_state = state;
  m_next_state = state;
}