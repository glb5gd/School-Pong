#ifndef MAIN_H
#define MAIN_H

using namespace std;

//Button constants
const long BUTTON_WIDTH{300};
const long BUTTON_HEIGHT{200};

//Screen dimension constants
const long SCREEN_WIDTH{640};
const long SCREEN_HEIGHT{480};

//Analog joystick dead zone
const long JOYSTICK_DEAD_ZONE{8000};

//sound settings
const long SOUND_FREQUENCY{44100};
const long NUM_HARDWARE_CHANNELS{2}; // Stereo
const long SAMPLE_SIZE{2048};

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "Pong_LTexture.h"
#include "Pong_Functions.h"
#include "Pong_Object_Interface.h"
#include "Pong_Paddle.h"
#include "Pong_Menu.h"
#include "Pong_Timer.h"
#include "Pong_Ball.h"
#include "Pong_Screen_Edge.h"
#include "Pong_Score_Graphic.h"
#include "Pong_Win_Graphic.h"
#include "Pong_P1Score.h"
#include "Pong_P2Score.h"
#include "Pong_Cursor.h"
#include "Pong_Title.h"
#include "Pong_Input.h"
#include "Pong_Wall.h"
#include "Pong_Wall2.h"
#include "Pong_Game_Mode.h"
#include "Pong_Sound.h"

#endif