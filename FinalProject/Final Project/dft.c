#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <string.h>
#include <sndfile.h>

#define BUFFERSIZE 256

//How to compile: clang Final.c -o Final libattopng.c -lsndfile 
//How to compile: clang Final.c -o Final -lsndfile

void DFT (double *DFTIn, double *DFTOut, long long N);
void DFT (double *DFTIn, double *DFTOut, long long N)
{
    for (int k = 0; k < N; k++)
    {
        DFTOut [k] = 0.0f;
        for (int n = 0; n < N; n++)
        {
            DFTOut[k] += DFTIn[n] * (cos ((2 * M_PI * k * n) / N));
        }
        DFTOut [k] /= N;
    }
}

void avgDFT (double *DFTIn, double *DFTOut, long long N);
void avgDFT (double *DFTIn, double *DFTOut, long long N) 
{
    double *buffer;

    buffer = malloc (BUFFERSIZE * sizeof(double));

    if (!buffer)
    {
        printf ("Error : Malloc failed.\n");
		return;
	}

    memset (buffer, 0.0, BUFFERSIZE);

    double *DFTbuffer;

    DFTbuffer = malloc (BUFFERSIZE * sizeof(double));

    if (!DFTbuffer)
    {
        printf ("Error : Malloc failed.\n");
        return;
	}

    int j = 0;

    for (int i = 0; i < N; i+=BUFFERSIZE)
    {
        DFT (DFTIn + i, DFTbuffer, BUFFERSIZE);
        j++;

        for (int n = 0; n < BUFFERSIZE; n++)
        {
            buffer[i] += DFTbuffer[i];
        }
    }

    for (int z = 0; z < BUFFERSIZE; z++)
    {
        buffer[z] /= j;
        DFTOut[z] = buffer[z];
    }
}