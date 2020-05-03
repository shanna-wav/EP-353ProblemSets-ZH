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