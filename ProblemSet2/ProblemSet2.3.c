#include <stdio.h>
#include <stdlib.h>

int main(){
    float frequency = 261.626;
    float decibel = -10.5;

    printf("This tone has:\nFrequency of %0.3fHz\nDecibel level of %0.1fdB\n", frequency, decibel);

return 0;
}