#include<stdio.h>
#include<stdlib.h>
long int scr_size(const char *scr_file)
{
    FILE *fscr;
    unsigned int width, height;
    long int scr_size;
    char ch;

    fscr = fopen(scr_file,"r");
    if (fscr == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", scr_file);
    	exit(1);
    } 

        // Seek to 18th byte
    fseek(fscr, 18, SEEK_SET);
    // Read the width (an int)
    fread(&width, sizeof(int), 1, fscr);
    // Read the height (an int)
    fread(&height, sizeof(int), 1, fscr);

    scr_size = width * height * 3;

    return scr_size;
}

