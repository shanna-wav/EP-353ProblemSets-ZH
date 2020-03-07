#include <stdio.h>
#include <stdlib.h>

typedef struct Note {
	unsigned char pitch;
	unsigned char velocity;
	unsigned char channel;
} Note; 

void printNote(Note *note);
void printNote(Note *note){
    printf("The MIDI note has: \n");
    printf("Pitch -> %d\n", note->pitch);
    printf("Velocity -> %d\n", note->velocity);
    printf("Channel -> %d\n", note->channel);
}

int main() {

    Note *note = (Note *) malloc(sizeof(Note));

    if (note == NULL) {
        fprintf(stderr, "malloc failed\n");
        return -1;
    }

    printf("Input MIDI pitch value: ");
    scanf("%hhu", &note->pitch);

    printf("Input MIDI velocity value: ");
    scanf("%hhu", &note->velocity);

    printf("Input MIDI channel value: ");
    scanf("%hhu", &note->channel);

    printNote(note);

    free(note);

    return 0;
}

