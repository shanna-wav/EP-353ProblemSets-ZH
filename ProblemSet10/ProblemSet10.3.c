#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

#define kInputFileName "eBass.wav"
#define kOutputFileName "BassBooster.wav"

//Struct to hold sndfile and sfinfo together
typedef struct SoundFile
{
    SNDFILE *file;
    SF_INFO info;
} 
SoundFile;

//Defining functions
int openInputSndFile(SoundFile*);

int createOutputSndFile(SoundFile *inFile, SoundFile *outFile);

void process(float *inBuffer, float *outBuffer, sf_count_t bufferSize);

//DSP function

float saturate (float samp);
float saturate (float samp)
{
    float x = fmin (fmax (-1.0, samp), 1.0);
    return x;
}

float BassBoosta (float sample)
{
    static float selectivity, gain1, gain2, ratio, cap;
    ratio = 0.75;
    selectivity = 70.0;
    gain2 = 2.0;
    gain1 = 1.0 / (selectivity + 1.0);
    cap = (sample + cap * selectivity ) * gain1;
    sample = saturate((sample + cap * ratio) * gain2);
    return sample;
}

//Main function
int main(void)
{
    SoundFile inFile, outFile;
  
    //Open input file
    int error = openInputSndFile(&inFile);

    if(error) return 1;

    //Get buffer size
    sf_count_t bufferSize = inFile.info.frames;

    //Allocate buffers for sound processing
    float *inBuffer = (float *) malloc(bufferSize*sizeof(float));
    float *outBuffer = (float *) calloc(bufferSize,sizeof(float));

    //Copy file content to the buffer
    sf_read_float(inFile.file, inBuffer, bufferSize);
  
    //process inBuffer and copy the result to outBuffer
    process(inBuffer, outBuffer, bufferSize);
  
    //Create output file
    error = createOutputSndFile(&inFile, &outFile);

    if(error) return 1;
    //Write result into output file
    sf_write_float(outFile.file, outBuffer, bufferSize);
  
    //Clean up
    sf_close(inFile.file);
    sf_close(outFile.file);
    free(inBuffer);
    free(outBuffer);
  
    return 0;
}

//DSP Implementation
void process (float *inBuffer, float *outBuffer, sf_count_t bufferSize)
{
    for (sf_count_t n = 0; n < bufferSize; n++)
    {
        outBuffer[n] = BassBoosta (inBuffer[n]);
    }
}

//Open input file in read mode
int openInputSndFile(SoundFile *sndFile)
{
    //Initialize SF_INFO with 0s
    memset(&sndFile->info, 0, sizeof(SF_INFO));
  
    sndFile->file = sf_open(kInputFileName, SFM_READ, &sndFile->info);

    if(!sndFile->file)
    {
        printf("Error : could not open file : %s\n", kInputFileName);
		puts(sf_strerror(NULL));
		return 1;
    }

    //Check the file format
    if(!sf_format_check(&sndFile->info))
    {	
        sf_close(sndFile->file);
		printf("Invalid encoding\n");
		return 1;
	}

    //Check if the file is mono
    if(sndFile->info.channels > 1)
    {
        printf("Input file is not mono\n");
        return 1;
    }

    //print out information about opened sound file
    printf("Sample rate for this file is %d\n", sndFile->info.samplerate);
	printf("A number of channels in this file is %d\n", sndFile->info.channels);
    printf("A number of frames in this file is %lld\n", sndFile->info.frames);
    printf("time is %f\n", (double)sndFile->info.frames / sndFile->info.samplerate);

    return 0;
}

//Open output file in write mode
int createOutputSndFile(SoundFile *inFile, SoundFile *outFile)
{
    outFile->file = sf_open(kOutputFileName, SFM_WRITE, &inFile->info);
    if(!outFile->file)
    {
        printf("Error : could not open file : %s\n", kOutputFileName);
		puts(sf_strerror(NULL));
		return 1;
	}
    return 0;
}