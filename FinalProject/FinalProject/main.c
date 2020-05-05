#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <string.h>
#include <sndfile.h>

//HOW TO COMPILE: clang main.c -o main -lsndfile

#define BUFFERSIZE 256

//Complex structure acts as complex number, holding real and imaginary values.

typedef struct complex
{
    double real;
    double imag;
} complex;

/*Function created for FFT. This separates odd/even or real/imaginary values and reorganizes
so that the real values are calculated at the start of inStart, 
and the imaginary values are calculated after.*/

void partition (complex *inStart, complex *inEnd);
void partition (complex *inStart, complex *inEnd)
{
    //Defining temporary array to store complex values. 
    //Length of array is N: distance between start and end of buffer.

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

/*FFT function using "divid and conquer" or "Cooley Turkey" method.
DFT formula used and separated into real and imaginary values.
Values are reassigned to inStart in chronological order.*/

void FFT (complex *inStart, complex *inEnd);
void FFT (complex *inStart, complex *inEnd)
{
    int N = inEnd - inStart;

    if (N < 2) return;

    else 
    {
        partition (inStart, inEnd);

        FFT (inStart, inStart + (N/2));
        FFT (inStart + (N/2), inEnd);

        for (int i = 0; i < (N/2); i++) 
        {
            complex even = *(inStart + i);
            complex odd = *(inStart + (N/2) + i);
            complex dft = {0, exp(-2.0 * M_PI * ((double)i / (double)N))};
            dft.real = (dft.real * odd.real) + (dft.imag *odd.imag);
            dft.imag = (dft.real * odd.imag) + (dft.imag * odd.real);

            *(inStart + i) = even;
            (inStart + i)->real += dft.real;
            (inStart + i)->imag += dft.imag;
            *(inStart + (N/2) + i) = even;
            (inStart + (N/2) + i)->real -= dft.real;
            (inStart + (N/2) + i)->imag -= dft.imag;
        }
    }
}

//Main function for FFT implementation and bark definition.

int main() 
{
    //Creating soundfile to store sound file for evaluation.

    SNDFILE *sndFile;
	SF_INFO sfInfo;
    complex *buffer;

    memset(&sfInfo, 0, sizeof(SF_INFO));

    //Array to hold critical bandwidth ranges called "barks".

    int bark[25] = {0, 100, 200, 300, 400, 505, 630, 770, 915, 1080, 1265, 1475, 1720, 1990, 2310, 2690, 3125, 3625, 4350, 5250, 6350, 7650, 9400, 11750, 15250};
    
    sndFile = sf_open("sine.wav", SFM_READ, &sfInfo);

    if(!sndFile)
    {
        printf ("Error : could not open file.\n");
		puts (sf_strerror (NULL));
		return 1;
    }

    long long N = sfInfo.frames; 

    //Ceil and floor functions used for zero padding to avoid segmentation fault 11
    //Ensures base 2 values

    buffer = malloc (pow(2, ceil(log2(N))) * sizeof(complex));

    if (!buffer)
    {
        printf ("Error : Malloc failed.\n");
		return 1;
	}

    //Temporary buffer created so program can read sound file as double and not as complex.

    double *tempbuff = malloc (N * sizeof(double));

        if (!tempbuff)
    {
        printf ("Error : Malloc failed.\n");
		return 1;
	}

    sf_read_double (sndFile, tempbuff, N);

    for (int i = 0; i < pow(2, ceil(log2(N))); i++)
    {
        if (i > N) 
        {
            buffer[i].real = 0.0f;
            buffer[i].imag = 0.0f;
        }
        else 
        {
            buffer[i].real = tempbuff[i];
            buffer[i].imag = 0.0f;
        }
    }
    
    free(tempbuff);


    double *FFTresult = malloc (BUFFERSIZE * sizeof(double));

    if (!FFTresult)
    {
        printf ("Error : Malloc failed.\n");
		return 1;
	}

    //Manual "memset" for FFTresult array.

    for (int i = 0; i < BUFFERSIZE; i++)
    { 
        FFTresult[i] = 0.f; 
    }

    int f;
    for (f = 0; f < (int)pow(2, ceil(log2(N))); f+=256)
    {   
        if (f+255 < (int)pow(2, ceil(log2(N))))
        {
            FFT (buffer + f, buffer + f + 255);
            for (int i = 0; i < BUFFERSIZE; i++)
            {
                FFTresult[i] += (buffer + f + i)->real;
            }
        }
    }
    for (int i = 0; i < BUFFERSIZE; i++)
    {
        FFTresult[i] /= f;
    }

    printf ("FFT done.\n");

    double *barkout = malloc (24 * sizeof(double));

    if (!barkout)
    {
        printf ("Error : Malloc failed.\n");
		return 1;
	}

    int dividend = 0;
    int currentbark = 0;
    int binfreq;
    
    //BARK LOOP

    for (int bin = 0; bin < BUFFERSIZE; bin++)
    {
        binfreq = ((float) bin / BUFFERSIZE) * sfInfo.samplerate;
        printf ("samplerate: %d\n", sfInfo.samplerate);
        printf("FFT Value of Bin #%d at %dHz: %0.2lf\n", bin, binfreq, buffer[bin].real);
        for (int i = 0; i <25; i++)
        {
            if (binfreq >= bark[i] && binfreq <= bark[i+1])
            {
                if (i != currentbark) //beginning of new bark
                {
                    barkout[i] /= dividend;
                    dividend = 0;
                    currentbark += i;
                }
                barkout[i] += buffer[bin].real;
                dividend++;
                printf ("%f\n", barkout[i]);
            }
        }
    }

    for (int b = 0; b < 25; b++)
    {
        printf ("Bark Number %d Energy Value: %f\n", b, barkout[b]);
    }

    if(!sf_format_check(&sfInfo))
    {	
        sf_close(sndFile);
		printf("Invalid encoding\n");
		return 1;
	}

    free (buffer);
    free (barkout);
    return 0;
}