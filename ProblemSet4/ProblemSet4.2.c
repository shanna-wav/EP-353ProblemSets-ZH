#include <stdio.h>
#include <stdlib.h>

int min3 (int a, int b, int c);
int min3 (int a, int b, int c) {
    if (a < b && a < c)
    printf("The smallest value is a:  %d\n", a);
    else if (b < a && b < c)
    printf("The smallest value is b:  %d\n", b);
    else if (c < a && c < b)
    printf("The smallest value is c:  %d\n", c);
    else 
    printf("More than one value is the smallest.\nPlease reevaluate your life.\n");
    return 0;
}

int main() {
    int x;
    int y;
    int z;

    printf("Type in three integer values: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("You typed in the integer values: %d %d %d \n\n", x, y, z); 

    min3 (x, y, z);

    return 0;
}