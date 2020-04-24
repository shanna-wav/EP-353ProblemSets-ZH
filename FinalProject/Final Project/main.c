#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <string.h>
#include <sndfile.h>

#define BUFFERSIZE 256

//How to compile: clang Final.c -o Final libattopng.c -lsndfile 
//How to compile: clang Final.c -o Final -lsndfile

int main() 
{
    SNDFILE *sndFile;
	SF_INFO sfInfo;
    double *buffer;
    double *DFTOut;
    
    memset(&sfInfo, 0, sizeof(SF_INFO));

    sndFile = sf_open("00-calung1.wav", SFM_READ, &sfInfo);

    if(!sndFile)
    {
        printf ("Error : could not open file.\n");
		puts (sf_strerror (NULL));
		return 1;
    }

    long long N = sfInfo.frames;

    buffer = malloc (N * sizeof(double));

    if (!buffer)
    {
        printf ("Error : Malloc failed.\n");
		return 1;
	}

    DFTOut = malloc (BUFFERSIZE * sizeof(double));

    if (!DFTOut)
    {
        printf ("Error : Malloc failed.\n");
		return 1;
	}

    sf_read_double (sndFile, buffer, N);
    
    DFT (buffer, DFTOut, N);

    printf ("DFT done.\n");
    
    for (int p = 0; p < BUFFERSIZE; p++)
    {
        printf("DFT Value: %lf\n", DFTOut[p]);
    }

    if(!sf_format_check(&sfInfo))
    {	
        sf_close(sndFile);
		printf("Invalid encoding\n");
		return 1;
	}

    free (buffer);
    free (DFTOut);
    return 0;
}