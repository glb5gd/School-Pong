#include "Pong_Main.h"

bool init(SDL_Window* & window,
          SDL_Renderer* & renderer,
          SDL_Joystick* & game_controller,
          SDL_Haptic* & controller_haptic)
{
  //Initialize SDL
  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC) < 0)
  {
    printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    return false;
  }
  else
  {
    //Set texture filtering to linear
    if(SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1") == false)
    {
      printf("Warning: Linear texture filtering not enabled!");
    }
    //Check for joysticks
    if(SDL_NumJoysticks() < 1)
    {
      printf("Warning: No joysticks connected!\n");
    }
    else
    {
      //Load joystick
      game_controller = SDL_JoystickOpen(0);
      if(game_controller == nullptr)
      {
        printf("Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError());
      }
      else
      {
        //Get controller haptic device
        controller_haptic = SDL_HapticOpenFromJoystick(game_controller);
        if(controller_haptic == nullptr)
        {
          printf("Warning: Controller does not support haptics! SDL Error: %s\n", SDL_GetError());
        }
        else
        {
          //Get initialize rumble
          if(SDL_HapticRumbleInit(controller_haptic) < 0)
          {
            printf( "Warning: Unable to initialize rumble! SDL Error: %s\n", SDL_GetError() );
          }
        }
      }
    }

    //Create window
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == nullptr)
    {
      printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
      return false;
    }
    else
    {
      //Create vsynced renderer for window
      renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if(renderer == nullptr)
      {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
      }
      else
      {
        //Initialize renderer color
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);

        //Initialize PNG loading
        int imgFlags{IMG_INIT_PNG};
        if((IMG_Init(imgFlags) & imgFlags) == false)
        {
          printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
          return false;
        }

        //Initialize SDL_mixer
        if(Mix_OpenAudio(SOUND_FREQUENCY, MIX_DEFAULT_FORMAT, NUM_HARDWARE_CHANNELS, SAMPLE_SIZE) < 0)
        {
          printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
          return false;
        }
      }
    }
  }
  return true;
}

void close_SDL(SDL_Window* & window,
               SDL_Renderer* & renderer,
               SDL_Joystick* & game_controller,
               SDL_Haptic* & controller_haptic)
{
  SDL_HapticClose(controller_haptic);
  SDL_JoystickClose(game_controller);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  controller_haptic = nullptr;
  game_controller = nullptr;
  window = nullptr;
  renderer = nullptr;

  //Quit SDL subsystems
  Mix_Quit();
  IMG_Quit();
  SDL_Quit();
}