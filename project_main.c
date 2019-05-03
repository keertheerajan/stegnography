#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int decode(const char *scr_file, const char *des_file);
long int scr_size(const char *scr_file);
int char_count(const char *ip_file);
int validate(long int scr_size,int ip_ch_count);
int encoding_data(const char *scr_file,const char *ip_file,const char *des_file);
int main(int argc,char *argv[])
{
    char *scr_ext_ptr,*des_ext_ptr,*msg_ext_ptr;
    long int scr_s;
    int ip_ch_count;
    if( argc == 5 )
    {
    if( !strcmp(argv[1],"-e") )
    {
	printf("INFO: VERIFYING FILE TYPE.....\n");
	scr_ext_ptr = (char *)(argv[2] + (strlen(argv[2]) - 4));
	msg_ext_ptr = (char *)(argv[3] + (strlen(argv[3]) - 4));
	des_ext_ptr = (char *)(argv[4] + (strlen(argv[4]) - 4));
	if( !strcmp(scr_ext_ptr,".bmp") )
	{
	    printf("INFO : SOURCE FILE TYPE MATCHED\n");
	    if( !strcmp(msg_ext_ptr,".txt") )
	    {
		printf("INFO : FILE TO BE ENCODED TYPE MATCHED\n");
		if( !strcmp(des_ext_ptr,".bmp") )
		{
		    printf("INFO : DESTINATION FILE TYPE MATCHED\n");
		    
		    scr_s = scr_size(argv[2]);
		    ip_ch_count = char_count(argv[3]);

		    if(validate(scr_s,ip_ch_count))
		    {
			encoding_data(argv[2],argv[3],argv[4]);
			exit(0);
		    }
		    else
		    {
			printf("ERROR : ENCODING FAILED IP FILE SIZE EXCEEDED SCR FILE SIZE");
		    }
		}
		else
		{
		    printf("INFO : DESTINATION FILE TYPE NOT MATCHED\n");
		}

	    }
	    else
	    {
		printf("INFO : FILE TO BE ENCODED TYPE NOT MATCHED\n");
	    }
	    
	}
	else
	{
	    printf("INFO : SOURCE FILE TYPE NOT MATCHED\n");
	}
    }
    }
    else if(!strcmp(argv[1],"-d"))
    {
	scr_ext_ptr = (char *)(argv[2] + (strlen(argv[2]) - 4));
	des_ext_ptr = (char *)(argv[3] + (strlen(argv[3]) - 4));
	if( !strcmp(scr_ext_ptr,".bmp") )
	{
	    printf("INFO : SOURCE FILE TYPE MATCHED\n");
	    if( !strcmp(des_ext_ptr,".txt") )
	    {
		printf("INFO : DESTINATION FILE TYPE MATCHED\n");
		decode(argv[2],argv[3]);
		
	    }
	    else
	    {
		printf("INFO : DESTINATION FILE TYPE NOT MATCHED\n");
	    }

	}
	else
	{
	    printf("INFO : SOURCE FILE TYPE NOT MATCHED\n");
	}
    }
    else
    {
	printf("ERROR : INPUTS MISSING\nEG: ./a.out -e src.bmp ip.txt des.bmp\n");
    }
    return 0;
}

