#include <stdio.h>
#include <stdlib.h>
#include "libattopng.h"
#include <memory.h>
#include <math.h>
#include <string.h>
#include <sndfile.h>

//How to compile: clang Final.c -o Final libattopng.c -lsndfile 

void DFT (double *DFTIn, double *DFTOut, int N);
void DFT (double *DFTIn, double *DFTOut, int N)
{
    for (int k = 0; k < N - 1; k++)
    {
        for (int n = 0; n < N - 1; n++)
        {
            DFTOut[k] = DFTIn[n] * (cos (((2 * M_PI) / N) * k * n) - sin (((2 * M_PI) / N) * k * n));
        }
    }
}

void PNG (double *X, int N);
void PNG (double *X, int N)
{
    libattopng_t *png = libattopng_new(N*2, N*2, PNG_GRAYSCALE);
    
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            libattopng_set_pixel (png, x, y, (int) (256.0f * X[y]));
        }
    }

    libattopng_save (png, "test_DFT.png");
    libattopng_destroy (png);
}

int main() 
{
    SNDFILE *sndFile;
	SF_INFO sfInfo;
    double *buffer;
    double *DFTOut;
    
    memset(&sfInfo, 0, sizeof(SF_INFO));

    sndFile = sf_open("sine.wav", SFM_READ, &sfInfo);

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

    DFTOut = malloc (N * sizeof(double));

    if (!DFTOut)
    {
        printf ("Error : Malloc failed.\n");
		return 1;
	}

    //DFT (buffer, DFTOut, N);

    //PNG (DFTOut, N);

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