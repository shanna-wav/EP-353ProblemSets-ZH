#include <stdio.h>
#include <stdlib.h>

int main(){
char pitchclass = 'A';

switch (pitchclass) {
    case 'C':
    case 'c':
      printf("C is pitch class 0.\n");
      break;

    case 'D':
    case 'd':
      printf("D is pitch class 2.\n");
      break;

    case 'E':
    case 'e':
      printf("E is pitch class 4.\n");
      break;

    case 'F':
    case 'f':
      printf("F is pitch class 5.\n");
      break;

    case 'G':
    case 'g':
      printf("G is pitch class 7.\n");
      break;

    case 'A':
    case 'a':
      printf("A is pitch class 9.\n");
      break;

    case 'B':
    case 'b':
      printf("B is pitch class 11.\n");
      break;

    default:
      printf("This note is invalid.\n");
  }
  return 0;
}