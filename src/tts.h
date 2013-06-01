/*
Compile using folowing command
gcc -Wall -o speak speak.c -lespeak -I/usr/include/espeak/
*/

#define DEFAULT 0
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <speak_lib.h>
#include "SDL_thread.h"

void tts_init();
void tts_set_voice(char voice_name[]);
void tts_set_volume(int volume);
void tts_set_rate(int rate);
void tts_set_pitch(int pitch);
void tts_say(int rate,int pitch,const char* text, ...);
