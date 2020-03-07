#include <stdio.h>

//Swap functon that takes two pointer inputs and swaps the value in their address. 

void swap (int *a, int *b);
void swap (int *a, int *b) {
    int c;
    c = *b;
    *b = *a;
    *a = c;
}

//Sorting function that uses swap function to put inputs from smallest to largest. 

void sort3 (int *n1,int *n2,int *n3);
void sort3 (int *n1,int *n2,int *n3) {
    if (*n1 > *n2) swap(n1, n2);
    if (*n1 > *n3) swap(n1, n3);
    if (*n2 > *n3) swap(n2, n3);
}

int main() {

    int na;
    int nb;
    int nc;

    printf("Enter value for na here: ");
    scanf("%d", &na);

    printf("Enter value for nb here: ");
    scanf("%d", &nb);

    printf("Enter value for nc here: ");
    scanf("%d", &nc);

    printf("\nYou typed values: %d, %d, %d\n", na, nb, nc);

    sort3 (&na, &nb, &nc);
    printf("The value of na is: %d\nThe value of nb is: %d\nThe value of nc is: %d\n", na, nb, nc);

    /*After printing the results, when I hit 'return' in the terminal, 
    it doesn't let me exit until I use CONTROL + C.
    Is that normal? */ 
    
    return 0;
}