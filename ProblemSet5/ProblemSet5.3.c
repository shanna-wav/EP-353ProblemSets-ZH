#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

int sum;

for (int i = 0; i < argc; i++) {
    sum += atoi(argv[i]);
}

if (argc == 1) {
    printf("Input any arbitrary number of integers as command-line arguments to run this!\n");

    return 1;
}

printf("The sum of integers is: %d!\n", sum);

return 0;
}