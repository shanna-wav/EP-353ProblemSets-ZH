#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <string.h>
#include <sndfile.h>

#define BUFFERSIZE 256

typedef struct complex
{
    double real;
    double imag;
} complex;

//How to compile: clang main.c -o main -lsndfile

void partition (complex *inStart, complex *inEnd);
void partition (complex *inStart, complex *inEnd)
{
    int N = inEnd-inStart;
    complex *temp;
    temp = malloc(N * sizeof(complex));

    //Separating odd and even items into temp.
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            temp[(int)floor(i/2)] = inStart[i];
        }
        else
        {
            temp[(N/2) + (int)floor(i/2)] = inStart[i];
        }
        
    }
    //Putting temp into inStart in the new order.
    for (int i = 0; i < N; i++)
    {
        inStart[i] = temp[i];
    }
    free (temp);
}

void FFT (complex *inStart, complex *inEnd);
void FFT (complex *inStart, complex *inEnd)
{
    int N = inEnd - inStart;

    if (N < 2) return;

    else 
    {
        partition (inStart, inEnd);
    }

    FFT (inStart, inStart + (N/2));
    FFT (inStart + (N/2), inEnd);

    for (int i = 0; i < (N/2); i++) 
    {
        complex even = *(inStart + i);
        complex odd = *(inStart + (N/2) + i);
        complex dft = {0, exp(-2.0 * M_PI * i / N)};
        dft.real = (dft.real * odd.real) + (dft.imag *odd.imag);
        dft.imag = (dft.real * odd.imag) + (dft.imag * odd.real); //mafs

        *(inStart + i) = even;
        (inStart + i)->real += dft.real;
        (inStart + i)->imag += dft.imag;
        *(inStart + (N/2) + i) = even;
        (inStart + (N/2) + i)->real -= dft.real;
        (inStart + (N/2) + i)->imag -= dft.imag;
    }
}

int main() 
{
    SNDFILE *sndFile;
	SF_INFO sfInfo;
    complex *buffer;
    complex *FFTOut;
    
    memset(&sfInfo, 0, sizeof(SF_INFO));

    sndFile = sf_open("sine.wav", SFM_READ, &sfInfo);

    if(!sndFile)
    {
        printf ("Error : could not open file.\n");
		puts (sf_strerror (NULL));
		return 1;
    }

    long long N = sfInfo.frames;

    buffer = malloc (N * sizeof(complex));

    if (!buffer)
    {
        printf ("Error : Malloc failed.\n");
		return 1;
	}

    FFTOut = malloc (BUFFERSIZE * sizeof(complex));

    if (!FFTOut)
    {
        printf ("Error : Malloc failed.\n");
		return 1;
	}

    buffer = malloc (sizeof(buffer));


    buffer->real = malloc (BUFFERSIZE * sizeof(buffer->real));

    buffer->imag = malloc (BUFFERSIZE * sizeof(buffer->imag));
 

    sf_read_double (sndFile, buffer->real, N);
    sf_read_double (sndFile, buffer->imag, N);
    
    FFT (buffer, FFTOut);

    printf ("FFT done.\n");
    
    for (int p = 0; p < BUFFERSIZE; p++)
    {
        printf("FFT Value: %lf, %lf\n", FFTOut[p].real, FFTOut[p].imag);
    }

    if(!sf_format_check(&sfInfo))
    {	
        sf_close(sndFile);
		printf("Invalid encoding\n");
		return 1;
	}

    free (buffer);
    free (FFTOut);
    return 0;
}

//store results of fft into csb file and graph it there