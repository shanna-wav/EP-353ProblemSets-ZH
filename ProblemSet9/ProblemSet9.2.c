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
#define kFileName "MyTremolo.wav"

int main()
{
    SNDFILE *sndFile;
    SF_INFO sfInfo;
    double *buffer;

    double amplitude = 0.25;
    double frequency = 250.0;

    double ampLFO = 0.5;
    double freqLFO = 2.0;

    buffer = malloc(kNumChannels * kNumFrames * sizeof(double));
    if (!buffer)
    {
        printf ("Error : Malloc failed.\n");
        return 1;
    }

    memset(&sfInfo, 0, sizeof(SF_INFO)); 

    sfInfo.samplerate = kSampleRate;
    sfInfo.frames = kNumFrames;
    sfInfo.channels = kNumChannels;
    sfInfo.format = kFormat;

    sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo);

    if (!sndFile)
    {
        printf ("Error : could not open file : %s\n", kFileName);
        puts(sf_strerror (NULL));
        return 1;
    }
    
    for (int t = 0; t < kNumFrames; t++)
    {
        double sample = amplitude * sin(2.0 * M_PI * (frequency/kSampleRate) * t);
        double LFO = ampLFO * sin(2.0 * M_PI * (freqLFO/kSampleRate) * t - (M_PI / 2.0)) + 0.5f;
        double tremolo = sample * LFO;
        for(int c = 0; c < kNumChannels; c++)
        {
            buffer[kNumChannels * t + c] = tremolo;
        }
    }

    sf_count_t count = sf_write_double(sndFile, buffer, sfInfo.channels * kNumFrames);

    if (count != sfInfo.channels * kNumFrames)
    {
        puts(sf_strerror(sndFile));
    }

    sf_close(sndFile);
    free(buffer);

    return 0;
}