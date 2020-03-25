#include <stdio.h>
#include <stdlib.h>

typedef struct Note {
    unsigned char pitch;
    unsigned char velocity;
    unsigned char channel;
} Note; 

int main () {
    FILE *file;

    Note note;

    file = fopen("MIDINotes.bin", "rb");

    if(!file){
        printf("Unable to open file.\n");
        return 1;
    }

    Note *array = malloc(sizeof(Note));

    if (array == NULL) {
        fprintf(stderr, "malloc failed\n");
        return -1;
    }

    int arraylength = 1;

    while (fread(&note, sizeof(Note), 1, file)!= 0) {
       array = realloc(array, arraylength * sizeof(Note));
       printf("MIDINote %d contains: Pitch: %d, Velocity: %d, Channel: %d\n", arraylength, note.pitch, note.velocity, note.channel); 
       array[arraylength - 1] = note;
       arraylength++;
    }

fclose(file);
free(array);

return 0;

}



