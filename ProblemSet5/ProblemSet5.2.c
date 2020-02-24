#include <stdio.h>
#include <string.h>

int characterExists (char letter, char alphabets[52]);
int characterExists (char letter, char alphabets[52]) {
    for (int i = 0; i < 52; i++) {
        if (letter == alphabets[i]) {
            printf("A character %c exists in the alphabets string.\n", letter);
            return 1;
        }
    }
    printf("A character %c does nots exists in the alphabets string.\n", letter);
    return 0;
}

int main() {

char c;
scanf("%c", &c);
printf("You typed the character: %c\n", c);

char letter = c;

char alphabets[53]; 

for (int i = 0; i < 26; i++) {
    alphabets[i] = 'A' + i;
}

for (int i = 26, j = 0; i < 52; i++, j++) {
    alphabets[i] = 'a' + j;
}

for (int i = 0; i < 52; i++) {
    printf("Index value %d contains element value %c\n", i, alphabets[i]);
}

characterExists(letter, alphabets);

return 0;
}

//Zac helped me with letter == alphabet[i] and with variable scope.