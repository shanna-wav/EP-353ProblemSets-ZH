#include <stdio.h>
#include <stdlib.h>

int main() {

FILE *readFile;

readFile = fopen("LoremIpsum.txt", "r");

if (readFile == NULL){
    printf("File cannot be opened.");
    return 1;
}

int count;
int line = 1;

while ((count = fgetc(readFile)) != EOF) {
    if (count == '\n') {
        printf ("Line Number: %d\n", line);
        line++;
    }
}

if(readFile) fclose(readFile);
return 0;
}