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
        for (int n = 0; n < N - 1; n++)
        {
            DFTOut[k] = DFTIn[n] * (cos ((2 * M_PI * k * n) / N));
        }
        DFTOut [k] /= (double) N;
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
    
    avgDFT (buffer, DFTOut, N);

    printf ("DFT done.\n");
    printf ("DFT Value: %lf\n", DFTOut[0]);

    //Make PNG:

    // #include "libattopng.h"

    // libattopng_t *png = libattopng_new(BUFFERSIZE, BUFFERSIZE, PNG_GRAYSCALE);
    
    // for (int y = 0; y < BUFFERSIZE; y++)
    // {
    //     for (int x = 0; x < BUFFERSIZE; x++)
    //     {
    //         libattopng_set_pixel (png, x, y, (int) (256.0f * DFTOut[y]));
    //     }
    // }

    // libattopng_save (png, "test_DFT.png");
    // libattopng_destroy (png);
    // printf ("PNG done.\n");

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