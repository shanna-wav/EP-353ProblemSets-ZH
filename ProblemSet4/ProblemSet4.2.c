#include <stdio.h>
#include <stdlib.h>

//The algorithm for minimum function is fixed from its original version! 
//Originally this used a bunch of if-else statements which was not needed. 

int minimum (int a, int b, int c);
int minimum (int a, int b, int c) {
    int min = a;
    if (min > b) min = b;
    if (min > c) min = c;
    printf("The smallest value is: %d.\n", min);

    return min;
}

int main() {

int x;
int y;
int z;

printf("Type in three integer values: ");
scanf("%d %d %d", &x, &y, &z);
printf("You typed in the integer values: %d %d %d \n\n", x, y, z); 

minimum (x, y, z);

return 0;
}