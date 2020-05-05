#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <string.h>
#include <sndfile.h>

//HOW TO COMPILE: clang main.c -o main -lsndfile

#define BUFFERSIZE 256
#define FILENAME "Sine2000.wav"

//Complex structure acts as complex number, holding real and imaginary values.

typedef struct complex
{
    double real;
    double imag;
} complex;

/*Function created for FFT. This separates odd/even values and reorganizes them,
so that all of even values are in front of buffer, and odd values are in the back half.*/

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

    //Zero padding for N to avoid segmentation fault + ensure divisibility. 

    if (N < 2) return;

    else 
    {
        //Implement partition in FFT to reorganize real and imaginary values.

        partition (inStart, inEnd);

        //Calling function inside function for recursion. 

        FFT (inStart, inStart + (N/2));
        FFT (inStart + (N/2), inEnd);

        //Main part of this function. 
        //Applying DFT equation to real and imaginary values.

        for (int i = 0; i < (N/2); i++) 
        {
            //Temporary complex values to store even and add values.
            //Organized in dft struct. 
            complex even = *(inStart + i);
            complex odd = *(inStart + (N/2) + i);
            complex dft = {0, exp(-2.0 * M_PI * ((double)i / (double)N))};
            dft.real = (dft.real * odd.real) + (dft.imag *odd.imag);
            dft.imag = (dft.real * odd.imag) + (dft.imag * odd.real);

            //Reassigning odd and even calculations to inStart/buffer in order from dft.

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
    SNDFILE *sndFile;
	SF_INFO sfInfo;
    complex *buffer;

    memset(&sfInfo, 0, sizeof(SF_INFO));

    //Array to hold critical bandwidth ranges called "barks".

    int bark[25] = {0, 100, 200, 300, 400, 505, 630, 770, 915, 1080, 1265, 1475, 1720, 1990, 2310, 2690, 3125, 3625, 4350, 5250, 6350, 7650, 9400, 11750, 15250};

   //Make soundfile to read.

    sndFile = sf_open(FILENAME, SFM_READ, &sfInfo);

    if(!sndFile)
    {
        printf ("Error : could not open file.\n");
		puts (sf_strerror (NULL));
		return 1;
    }

    //Assign length of audiofile to variable N.

    long long N = sfInfo.frames; 

    //Make text file to store results of program.

    FILE *file;

    file = fopen("FinalResults.txt", "w");

    if(file == NULL)
    {
        printf("File cannot be opened.\n");
        return 1; 
    }

    fprintf (file, "Sample Rate is: %d Hz\n", sfInfo.samplerate);
    fprintf (file, "Number of frames is: %lld Hz\n", N);

    //Ceil function for zero padding to ensures base 2 values.

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

    //Read soundfile into tempbuff.

    sf_read_double (sndFile, tempbuff, N);

    //Place tempbuff values back into buffer to use buffer for FFT.

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

    //Create array to hold FFT frequency values.

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

    //Implement FFT function at 256 increments.

    for (f = 0; f < (int)pow(2, ceil(log2(N))); f+=256)
    {   
        if (f+255 < (int)pow(2, ceil(log2(N))))
        {
            FFT (buffer + f, buffer + f + 255);
            
            //Store FFT values temporarily in FFT result.
            //Get value of each sample in buffer.

            for (int i = 0; i < BUFFERSIZE; i++)
            {
                FFTresult[i] += (buffer + f + i)->real;
            }
        }
    }

    //Find average of each bin. 

    for (int i = 0; i < BUFFERSIZE; i++)
    {
        FFTresult[i] /= f;
    }

    printf ("FFT Completed.\n");

    //Create array to temporarily store bark values.

    double *barkout = malloc (24 * sizeof(double));

    if (!barkout)
    {
        printf ("Error : Malloc failed.\n");
		return 1;
	}

    //Defining variables for bark loop.

    int dividend = 0;
    int currentbark = 0;
    int binfreq;
    
    //Bark function uses equation of 1/buffersize * samplerate to determine frequency of each bin.

    for (int bin = 0; bin < BUFFERSIZE; bin++)
    {
        binfreq = ((float) bin / BUFFERSIZE) * sfInfo.samplerate;
        fprintf(file, "FFT Value of Bin #%d at %dHz: %0.2lf\n", bin, binfreq, buffer[bin].real);
        for (int i = 0; i <25; i++)
        {
            //Resets current bark each time a bark is filled and the average is taken.

            if (binfreq >= bark[i] && binfreq <= bark[i+1])
            {
                if (i != currentbark)
                {
                    barkout[i] /= dividend;
                    dividend = 0;
                    currentbark += i;
                }

                //Adding bin frequency to specific bandwidth. 

                barkout[i] += buffer[bin].real;
                dividend++;
            }
        }
    }

    

    if(!sf_format_check(&sfInfo))
    {	
        sf_close(sndFile);
		printf("Invalid encoding\n");
		return 1;
	}

    //Prints values in critical bandwidths into txt file. 

    for (int b = 0; b < 25; b++)

    {   
        fprintf (file, "Bark Number %d Energy Value: %f\n", b, barkout[b]);
    }

    printf ("Completed. View in FinalResults.txt.\n");
    printf ("Highest value represents critical bandwidth with most frequency energy.\n");

    //Clean up. 

    if(file) 
    {
        fclose(file);
    }

    free (buffer);
    free (barkout);
    return 0;
}