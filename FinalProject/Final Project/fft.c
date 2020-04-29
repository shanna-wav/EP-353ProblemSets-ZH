#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <string.h>
#include <sndfile.h>

typedef struct complex
{
    double real;
    double imag;
} complex;

void partition (complex *inStart, complex *inEnd);
void partition (complex *inStart, complex *inEnd)
{
    int N = inEnd-inStart;
    complex *snuggle;
    snuggle = malloc(N * sizeof(complex));

    //Separating odd and even items into snuggle.
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            snuggle[(int)floor(i/2)] = inStart[i];
        }
        else
        {
            snuggle[(N/2) + (int)floor(i/2)] = inStart[i];
        }
        
    }
    //Putting snuggle into inStart in the new order.
    for (int i = 0; i < N; i++)
    {
        inStart[i] = snuggle[i];
    }
    free (snuggle);
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