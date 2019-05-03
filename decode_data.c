#include<stdio.h>
#include<stdlib.h>
char *decode_data(const char *scr_file, int size)
{
    static  int byte_count=54;
    unsigned char magic_char = 0,value;
 
    FILE *fscr;
    fscr = fopen(scr_file,"r");
    if (fscr == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", scr_file);
    	exit(1);
    }

    fseek(fscr,byte_count,SEEK_SET);

    char *str = (char *)calloc(size,sizeof(char));

    for(int i = 0,pos; i < size; i++)
    {
	magic_char = 0;
	pos = 7;
	//fread(&value,sizeof(char),1,fscr);
	for(int j = 0; j < 8; j++)
	{
	    fread(&value,sizeof(char),1,fscr);
	    byte_count++;
	    if(value & 1)
	    {
		magic_char = magic_char | (1<<pos);
		pos--;
	    }
	    else
	    {
		pos--;
	    }
	}
	str[i] = magic_char;
	
    }
    return str;
}
  

    


