#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//static int byte_count = 54;
char *decode_data(const char *scr_file,int size);
int decode(const char *scr_file, const char *des_file)
{
    FILE *fscr,*fdes;
    
    char *return_str;
    char password_size[2]={0,};
    char password[5]={0,},ch;
    int size,file_size;
    fscr = fopen(scr_file,"r");
    if (fscr == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", scr_file);
    	exit(1);
    }

    fdes = fopen(des_file,"w");
    if (fdes == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", des_file);
    	exit(1);
    }

    return_str = decode_data(scr_file,2);
    printf("%s",return_str);

    if( !strcmp(return_str, "#*") )
    {
	printf("INFO : MAGIC STRING IS PRESENT\n");
	printf("ENTER THE SIZE OF PASSWORD: \n");
	fgets(password_size,2,stdin);
	getchar();
	printf("ENTER THE PASSWORD: \n");
	size = atoi(password_size);
	fgets(password,size+1,stdin);

	return_str = decode_data(scr_file,1);
	if( !strcmp(password_size,return_str) )
	{
	    free(return_str);
	    return_str = decode_data(scr_file,5);
	    if( !strcmp(return_str, password) )
	    {
		free(return_str);
		return_str = decode_data(scr_file,1);
		file_size = atoi(return_str);
		free(return_str);
		printf("INFO: PASSWORD MATCHED\nDECODING STARTED .....\n");
		return_str = decode_data(scr_file,file_size);
		for(int i=0;i<file_size;i++)
		{
		    ch = return_str[i] ;
		    fwrite(&ch,sizeof(char),1,fdes);
		}
		free(return_str);
	    }
	    else
	    {
		printf("INFO: INVALID PASSWORD\n");
	    }
	}
	else
	{
	    printf("INFO: ERROR: INCORRECT PASSWORD\n");
	}

	
    }
    else
    {
	printf("INFO: NOTHING IS HIDDEN TO BE ENCODED\n");
    }

    return 0;
}



 

    

