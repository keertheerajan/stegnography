#include<stdio.h>
#include<stdlib.h>
int char_count(const char *ip_file)
{
    FILE *fip;
    int ip_ch_count=0, size;
    char ch;

    fip  = fopen(ip_file,"r");
    if (fip == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", ip_file);
    	exit(1);
    }

    while( (ch=fgetc(fip)) != EOF )
    {
	ip_ch_count++;
    }

    return ip_ch_count;
}
