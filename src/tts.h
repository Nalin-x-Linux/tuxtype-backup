/*
Compile using folowing command
gcc -Wall -o speak speak.c -lespeak -I/usr/include/espeak/
*/

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <speak_lib.h>
#include "SDL_thread.h"


//Espeak 
espeak_POSITION_TYPE position_type;

void tts_init();
void tts_set_voice_by_name(char voice_name[]);
void tts_set_volume(int volume);
void tts_set_rate(int rate);
void tts_set_pitch(int pitch);
void tts_say(const char* text, ...);
