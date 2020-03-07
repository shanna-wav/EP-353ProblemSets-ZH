#include <stdio.h>
#include <stdlib.h>

int main () {
    int input;
    int counter = 0;

    int *array = malloc(sizeof(int));

    if (array == NULL) {
        fprintf(stderr, "malloc failed\n");
        return -1;
    }

    while (input > 0){
        printf("Type integers here.\n");
        printf("When fulfilled, type a negative integer:");
        scanf("%d", &input);

        if (input < 0) break;

        counter++;
        array = realloc(array, counter * sizeof(int));
        array[counter - 1] = input;
    }
  
    printf("Integers entered by the user are: \n");
        for (int i = 0; i < counter; i++){
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}