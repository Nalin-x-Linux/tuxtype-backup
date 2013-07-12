#include "globals.h"

wchar_t* arrange_in_order(wchar_t *disorder)
{
	int iter=0,i,j,len;
	wchar_t *ordered = malloc(sizeof(char)*100);
	wchar_t *order = malloc(sizeof(char)*100);
	
	len = wcslen(disorder);	
	ordered[iter] = L'\0';
	wcscpy(order,L"fdsjkl");	
		
	for(i=0;i<6;i++)
	{
		
		for(j=0;j<len;j++)
		{
			if (order[i] == disorder[j])
			{				
				ordered[iter] = order[i];
				iter++;
			}
		}
	}
	ordered[iter] = L'\0';
	return ordered;
}


int braille_language_loader(char* language)
{
	int iter = 0;
	FILE *fp;
	char file[100];
	
	sprintf(file , "%s/braille/%s", settings.default_data_path,language);
	fp = fopen(file,"r");
	
	if(fp == NULL)
		return 0;
			
	while(!feof(fp))
	{
		fscanf(fp,"%S %S\n",braille_key_value_map[iter].key,braille_key_value_map[iter].value);
		iter++;
	}
	return 1;
}
