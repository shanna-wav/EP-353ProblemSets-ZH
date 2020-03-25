#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <sndfile.h>

int main() {
    SNDFILE *sndFile = NULL; 
	SF_INFO sfInfo; 

    memset(&sfInfo, 0, sizeof(SF_INFO)); 

    char *array[3] = {"00-calung1.wav", "05-gangsahi1.wav", "10-gangsamid1.wav"};

    for (int i = 0; i < 3; i++) {
        sndFile = sf_open(array[i], SFM_READ, &sfInfo);

        if(!sndFile){
            printf ("Error : could not open file\n");
		    exit(2);
        }

        printf("Sample rate for file %s is: %d\n", array[i], sfInfo.samplerate);
	    printf("Number of channels in file %s is: %d\n", array[i], sfInfo.channels);
        printf("Number of frames in file %s is: %lld\n", array[i], sfInfo.frames);
        printf("Time is: %f seconds\n", (double)sfInfo.frames / sfInfo.samplerate);

        if(sndFile){ 
		    sf_close(sndFile);
		    sndFile = NULL;
	    }
    }

	return 0;
}

