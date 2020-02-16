#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float baseFrequency = 440.0;

float freq2midi(float freq);
float freq2midi(float freq) {
    float MIDI  =  12*log2(freq/baseFrequency) + 69;
    printf("The MIDI note number of %0.2f is %0.2f\n", freq, MIDI);
    return MIDI; 
}

int main() {
    float freq = 100;
    freq2midi(freq);
    return 0;
}