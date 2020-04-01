#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sndfile.h> 

#define kBufferSize 4096

void invert(float *buffer, int numsamples);
void invert(float *buffer, int numsamples) {
    for (int i = 0; i < numsamples; i++)
    {
        buffer[i] *= -1.0f;
    }
}

int main() 
{

    SNDFILE *inFile = NULL, *outFile = NULL;
    SF_INFO sfInfo;

    static float buffer[kBufferSize];

    memset(&sfInfo, 0, sizeof(SF_INFO));

    inFile = sf_open("sine.wav", SFM_READ, &sfInfo);
    if (!inFile)
    {
        printf ("Error : could not open file : sine.wav\n");
        puts (sf_strerror (NULL));
        return 1;
    }
    
    if(!sf_format_check(&sfInfo))
    {	
        sf_close(inFile);
        printf("Invalid encoding\n");
        return 1;
    }

    outFile = sf_open("sineInverted.wav", SFM_WRITE, &sfInfo);


    if (!outFile)
    {	
        printf ("Error : could not open file : sineInverted.wav");
        puts (sf_strerror(NULL));
        return 1;
    }

    int readcount;
    while((readcount = sf_read_float(inFile, buffer, kBufferSize)) > 0) 
    {
        printf("%d\n",readcount);
        invert(buffer, readcount);
        sf_write_float(outFile, buffer, readcount); 
    }

    sf_close(inFile);
    sf_close(outFile);

    return 0;
}