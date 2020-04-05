#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

#define kSampleRate 44100
#define kSec 1
#define kNumFrames (kSampleRate * kSec)
#define kNumChannels 2
#define kFormat (SF_FORMAT_WAV | SF_FORMAT_PCM_24)
#define kFileName "TriangleWave.wav"

int main (void)
{
    //Create sound file, location for sf info, array for buffer
    SNDFILE *sndFile;
    SF_INFO sfInfo;
    double *buffer;

    //Sound parameters
    double amplitude = 0.25;
    double frequency = 250.0;
    int numHarmonics = 100;
    double sample;

    //Creating two channels for buffer with dynamic allocation
    buffer = malloc(kNumChannels * kNumFrames * sizeof(double));

    if (!buffer)
    {
        printf ("Error : Malloc failed.\n");
		return 1;
	}

    //Initialize sfInfo with all zeros
    memset(&sfInfo, 0, sizeof(SF_INFO));

    //Set sound file parameters
    sfInfo.samplerate = kSampleRate;
	sfInfo.frames = kNumFrames;
	sfInfo.channels = kNumChannels;
	sfInfo.format = kFormat;

    //Open sound file in write mode
    sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo);

    if(!sndFile)
    {
        printf ("Error : could not open file : %s\n", kFileName);
		puts(sf_strerror (NULL));
		return 1;
    }

    //Build triangle wave
    //Amplitude is multiplied by 1/x**2
    //Alternating between + and -
    for (int time = 0; time < kNumFrames; time++)
    {
        for (int i = 1; i <= numHarmonics; i+=2)
        {
            if (frequency * i < kSampleRate / 2)
            {
                sample = (amplitude / pow(i, 2.0)) * sin (2.0 * M_PI * ((frequency * i)/kSampleRate) * time);
                if ((i + 1) % 4 == 0)
                {
                    sample *= -1.0;
                }
                for (int c = 0; c < kNumChannels; c++)
                {
                    buffer [kNumChannels * time + c] += sample;
                }
            }
        }
    }

    //Write result into sound file
    sf_count_t count = sf_write_double(sndFile, buffer, sfInfo.channels * kNumFrames);

    if(count != sfInfo.channels * kNumFrames)
    {
        puts(sf_strerror(sndFile));
    }

    //Clean up
    sf_close(sndFile);
    free(buffer);
    return 0;
}