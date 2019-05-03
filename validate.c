#include<stdio.h>
int validate(long int scr_size,int ip_ch_count)
{
    if((ip_ch_count*8)<scr_size)
	return 1;
    else
	return 0;
}
