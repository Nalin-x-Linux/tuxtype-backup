/*
Compile using folowing command
gcc -Wall -o speak speak.c -lespeak -I/usr/include/espeak/
*/

#define DEFAULT_VALUE 0
#define INTERRUPT 0
#define APPEND 1

#define DEFAULT 0
#include "globals.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <speak_lib.h>
#include <stdarg.h>
#include "SDL_thread.h"

typedef struct
{
	int interrupt;
	char text[1000];
}tts_argument;

//TTS Thread function
int tts_thread_func(void *arg)
{
	espeak_POSITION_TYPE position_type = POS_CHARACTER;
	tts_argument recived = *((tts_argument*)(arg));
	fprintf(stderr,"\nSpeaking : %s with interrupt :  %d",recived.text,recived.interrupt);
	
	
	if (recived.interrupt == INTERRUPT)
		tts_cancel();
	else
		tts_wait();
	
	int Size = strlen(recived.text)+1;
	espeak_Synth(recived.text, Size, 0, position_type, 0,	espeakCHARS_AUTO,0, NULL);	
	espeak_Synchronize();
	return 1;
}


//This function should be called at begining 
void tts_init()
{
	espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 500, NULL, 0 );
}


void tts_cancel()
{
	espeak_Cancel();
}

void tts_wait()
{
	while (espeak_IsPlaying() && tts_thread)
		{};
	SDL_Delay(30); 
}


//Used to set person in TTS. in the case of espeak we will set language by this.
void tts_set_voice(char voice_name[]){
	espeak_SetVoiceByName(voice_name);
}


//Stop the speech if it is working
void tts_stop(){
	if (tts_thread)
    {
		SDL_KillThread(tts_thread);
		tts_thread = NULL;
        espeak_Cancel();
    }
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
	tts_argument data_to_pass;
	
	//Setting given rate if rate != 0
	//if (rate != DEFAULT_VALUE)
	//T4K_Tts_set_rate(rate);

    //Setting pitch rate if rate != 0
    //if (pitch != DEFAULT_VALUE)
    //T4K_Tts_set_pitch(pitch);

	//Getting the formated text
	char to_say[1000];
	va_list list;
	va_start(list,text);
	vsprintf(to_say,text,list);
	va_end(list);
	
	
	data_to_pass.interrupt = interrupt;
	strcpy(data_to_pass.text,to_say);
	
	//Calling threded function to say.	
	tts_thread = SDL_CreateThread(tts_thread_func, &data_to_pass);
}	
