#include <stdio.h>
#include <stdlib.h>
#include "libattopng.h"
#include <memory.h>
#include <math.h>
#include <string.h>
#include <sndfile.h>

//How to compile: clang Final.c -o Final libattopng.c -lsndfile 

void DFT (double *samples, int N, double *X);
void DFT (double *samples, int N, double *X)
{
    for (int k = 0; k < N; k++)
    {
        for (int n = 0; n < N; n++)
        {
            X[k] = samples[n] * (cos ((2 * M_PI / N) * k * n) - sin ((2 * M_PI / N) * k * n));
        }
    }
}

void PNG (float *X, int N);
void PNG (float *X, int N)
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