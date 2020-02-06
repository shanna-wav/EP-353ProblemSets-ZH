#include <stdio.h>
#include <math.h>

int main() {

char midiNote = 60; //ascii table 
// char is an integer that is limited in its range
float frequency;
frequency = (pow(2.0, (midiNote-69)/12.0) * 440.0); // last thing is times 440
// Two to the (how many octaves midiNote is from A4 times 440, the frequency value of A4)

printf("The frequency of a MIDI note number %d is %.02f Hz.\n", midiNote, frequency);

return 0;
}