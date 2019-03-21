#include "Pong_Main.h"

int main(int argc, char* args[])
{
  srand(time(0));

  vector<Abstract_Object*> obj_list;

  //The window we'll be rendering to
  SDL_Window* window{nullptr};

  //The window renderer
  SDL_Renderer* renderer{nullptr};

  //Game Controller 1 handler
  SDL_Joystick* game_controller{nullptr};
  SDL_Haptic* controller_haptic{nullptr};
  
  //Start up SDL and create window
  if(init(window, renderer, game_controller, controller_haptic) == false)
  {
    printf("Failed to initialize!\n");
  }
  else
  {
    //quit flag
    bool quit{false};

    //Event handler
    SDL_Event e;

    obj_list.push_back(new Title(renderer));
    obj_list.push_back(new Key_Space());
    obj_list.push_back(new Key_Up());
    obj_list.push_back(new Key_Down());
    obj_list.push_back(new Key_W());
    obj_list.push_back(new Key_S());

    //While the user hasn't quit
    while(quit == false)
    {
      while(SDL_PollEvent(&e) != 0)
      {
        if(e.type == SDL_QUIT)
        {
          quit = true;
        }
        for(long i{0}; i < obj_list.size(); ++i)
        {
          if(obj_list[i]->get_type() == "Input")
          {
            obj_list[i]->obj_main(obj_list, renderer, e);
          }
        }
      }

      for(long i{0}; i < obj_list.size(); ++i)
      {
        if(obj_list[i]->get_type() != "Input")
        {
         obj_list[i]->obj_main(obj_list, renderer, e);
        }
      }

      //Clear Screen
      SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
      SDL_RenderClear(renderer);

      for(long i{0}; i < obj_list.size(); ++i)
      {
        obj_list[i]->obj_render(renderer);
      }

      // Update Screen
      SDL_RenderPresent(renderer);
    }
  }

  while(obj_list.empty() == false)
  {
    delete obj_list[obj_list.size() - 1];
    obj_list[obj_list.size() - 1] = nullptr;
    obj_list.pop_back();
  }

  //Free resources and close SDL
  close_SDL(window, renderer, game_controller, controller_haptic);
  return 0;
}