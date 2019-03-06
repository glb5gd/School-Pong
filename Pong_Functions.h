#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//Starts up SDL and creates window
bool init(SDL_Window* & window,
          SDL_Renderer* & renderer,
          SDL_Joystick* & game_controller,
          SDL_Haptic* & controller_haptic);

void close_SDL(SDL_Window* & window,
               SDL_Renderer* & renderer,
               SDL_Joystick* & game_controller,
               SDL_Haptic* & controller_haptic);

#endif