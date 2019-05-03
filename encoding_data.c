#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
long int scr_size(const char *scr_file);
int char_count(const char *ip_file);
int encoding_data(const char *scr_file,const char *ip_file,const char *des_file)
{
    long int scr_s;
    int bit,count=0,ip_ch_count,total_string;
    unsigned char value;
    FILE *fsrc,*fdes,*fip;
    char *str = "#*512345",*full_str,ch;

      // Open the Source file
    fsrc = fopen(scr_file, "r");
    if (fsrc == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", scr_file);
    	exit(1);
    }

    fip  = fopen(ip_file,"r");
    if (fip == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", ip_file);
    	exit(1);
    }

    fdes = fopen(des_file, "w");
    if (fdes == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", des_file);
    	exit(1);
    }

    for(int i=0;i<54;i++)
    {
    	fread(&value, sizeof(char), 1, fsrc);
    	fwrite(&value, sizeof(char), 1, fdes);
    	count++;
    }

    ip_ch_count = char_count(ip_file);
    ch = ip_ch_count + '0';
    total_string = 8 + ip_ch_count + 1;
    full_str = calloc(total_string,sizeof(char));
    strcpy(full_str,str);
    full_str[8] = ch;
    for(int i=9;i<=total_string;i++)
    {
	fread(&full_str[i], sizeof(char), 1,fip);
    }
    puts(full_str);

    
    for(int i=0; full_str[i]!='\0' ; i++)
    {
	ch = full_str[i];
  	unsigned mask= 1 << (sizeof(ch)*8) - 1;
	for(; mask !=0 ; mask >>= 1)
	{
	    fread(&value, sizeof(char), 1, fsrc);
	    value = value & (~1);
	    if ( ch & mask )
		bit = 1;
	    else
		bit = 0;
	    printf("%d",bit);
	    value = value | bit;
	    fwrite(&value, sizeof(char), 1, fdes);
	    count++;
	}
	puts("");
	sleep(1);
	
    }

    scr_s = scr_size(scr_file)+55;//count starts from zero so 55
    for(int i=count; i<scr_s; i++)
    {
   	fread(&value, sizeof(char), 1, fsrc);
   	fwrite(&value, sizeof(char), 1, fdes);

    }

    return 0;
}


