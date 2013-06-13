/*
Compile using folowing command
gcc -Wall -o speak speak.c -lespeak -I/usr/include/espeak/
*/

#define DEFAULT_VALUE 0
#define INTERRUPT 0
#define APPEND 1

#define DEFAULT 0
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <speak_lib.h>
#include <stdarg.h>
#include "SDL_thread.h"


//TTS Thread function
int tts_thread_func(void *arg)
{
	int interrupt = *((int*)(arg));
        if (interrupt != INTERRUPT) 
        { 
                while (espeak_IsPlaying()) 
                { 
                        fprintf(stderr,"\nAlive"); 
                } 
        } 
	espeak_Synchronize();
	return 1;
}


//This function should be called at begining 
void tts_init()
{
	espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 500, NULL, 0 );
}

//Used to set person in TTS. in the case of espeak we will set language by this.
void tts_set_voice(char voice_name[]){
	espeak_SetVoiceByName(voice_name);
}


//Stop the speech if it is working
void tts_stop(){
	extern SDL_Thread *tts_thread;
	SDL_KillThread(tts_thread);
	espeak_Cancel();
}


//TTS Parameters
void tts_set_volume(int volume){
espeak_SetParameter(espeakVOLUME,2*volume,0);
}

void tts_set_rate(int rate){
espeak_SetParameter(espeakRATE,(3.7*rate)+80,0);
}

void tts_set_pitch(int pitch){
espeak_SetParameter(espeakPITCH,pitch,0);
}

void tts_say(int rate,int pitch,int interrupt, const char* text, ...){
	int *interrupt_address;
	extern SDL_Thread *tts_thread;

	espeak_POSITION_TYPE position_type = POS_CHARACTER;
		
	
			
	if (interrupt == INTERRUPT)
		tts_stop();
	
	//Setting given rate if rate != 0
	if (rate != DEFAULT_VALUE)
	tts_set_rate(rate);

        //Setting pitch rate if rate != 0
        if (pitch != DEFAULT_VALUE)
        tts_set_pitch(pitch);

	
	char out[1000];
	va_list list;
	va_start(list,text);
	vsprintf(out,text,list);
	va_end(list);
	
	int Size = strlen(out)+1;    
	espeak_Synth(out, Size, 0, position_type, 0,	espeakCHARS_AUTO,0, NULL);
	fprintf(stderr,"\nTTS_Say : %s\n",out);
	interrupt_address = &interrupt;
	tts_thread = SDL_CreateThread(tts_thread_func, interrupt_address);
}	
