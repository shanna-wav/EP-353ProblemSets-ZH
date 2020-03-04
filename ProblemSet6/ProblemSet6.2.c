#include <stdio.h>

//Function that counts how many times given character appears in string. 

int numChars (const char *s, char c);
int numChars (const char *s, char c) {
    int count = 0;
    while (*s != '\0') {
       if (*s == c) count++; 
       s++;
    }
    return count;
}

int main () {

    char *str;
    char c;

    printf("Write string here: ");
    scanf("%s%*c", str); 
    /* %*c is meant to discard 'new line' which was 
    previously causing weird problems that I did not understand.*/

    printf("Write character here: ");
    scanf("%c%*c", &c);

    int count = numChars (str, c);

    printf("\nThe number of times that character %c appears in the string is: %d.\n", c, count);

    return 0;
}