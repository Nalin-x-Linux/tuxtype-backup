/*
Compile using folowing command
gcc -Wall -o speak speak.c -lespeak -I/usr/include/espeak/
*/

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <speak_lib.h>
#include <stdarg.h>
#include "SDL_thread.h"


//TTS Thread function
void tts_thread_func(void *unused)
{
		espeak_Synchronize();
}


//This function should be called at begining 
void tts_init()
{
	espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 500, NULL, 0 );
}

//Used to set person in TTS. in the case of espeak we will set language by this.
void tts_set_voice_by_name(char voice_name[]){
	espeak_SetVoiceByName(voice_name);
}


//Stop the speech if it is working
void tts_stop(){
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


void tts_say(const char* text, ...){
	espeak_POSITION_TYPE position_type;
	espeak_Cancel();

	char out[400] = "";
	char temp[400] = "";

	va_list list;
	va_start(list,text);
	int i=0,len;
	while(i<strlen(text))
	{
			
		len = strlen(out);
		if(text[i] != '%')
		{
			out[len] = text[i];
			out[len+1] = '\0';
			i++;
		}
		else
		{
			if(text[i+1] == 'c')
			{
				out[len] = va_arg(list, int);
				out[len+1] = '\0';
				i+=2;
			}


			if(text[i+1] == 's')
			{
				strcat(out,va_arg(list, char*));
				i+=2;
			}
			else if(text[i+1] == 'd')
			{
				sprintf(temp,"%d",va_arg(list, int));
				strcat(out,temp);
				i+=2;
			}
			else if(text[i+1] == 'f')
			{
				sprintf(temp,"%f",va_arg(list, double));
				strcat(out,temp);
				i+=2;
			}

			else
			{
				i++;
			}			
		}	
	}	
	
	int Size = strlen(out)+1;    
	espeak_Synth(out, Size, 0, position_type, 0,	espeakCHARS_AUTO,0, NULL);
	SDL_CreateThread(tts_thread_func, NULL);
}





