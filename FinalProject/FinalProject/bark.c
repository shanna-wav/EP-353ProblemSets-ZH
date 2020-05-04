#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <string.h>
#include <sndfile.h>

int main() {  

  switch (freqbin) {
    case >= 0 && <= 100:
      printf("Bark 1\n");
      break;

    case >= 100  && <= 200:
      printf("Bark 2/n");
      break;

    case >= 200 0 && <= 300:
      printf("Bark 3/n");
      break;

    case >= 300 && <= 400:
      printf("Bark 4/n");
      break;

    case >= 395 && <= 505:
      printf("Bark 5/n");
      break;

    case >= 510 && <= 630:
      printf("Bark 6/n");
      break;

    case >= 630 && <= 770:
      printf("Bark 7/n");
      break;

    case >= 765 && <= 915:
      printf("Bark 8/n");
      break;

    case >= 920 && <= 1080:
      printf("Bark 9/n");
      break;

    case >= 1075 && <= 1265:
      printf("Bark 10/n");
      break;

    case >= 1265 && <= 1475:
      printf("Bark 11/n");
      break;

    case >= 1480 && <= 1720:
      printf("Bark 12/n");
      break;

    case >= 1710 && <= 1990:
      printf("Bark 13n");
      break;

    case >= 1990 && <= 2310:
      printf("Bark 14\n");
      break;

    case >= 2310 && <= 2690:
      printf("Bark 15\n");
      break;

    case >= 2675 && <= 3125:
      printf("Bark 16\n");
      break;

    case >= 3125 && <= 3625:
      printf("Bark 17\n");
      break;

    case >= 3650 && <= 4350:
      printf("Bark 18\n");
      break;

    case >= 4350 && <= 5250:
      printf("Bark 19\n");
      break;

    case >= 5250 && <= 6350:
      printf("Bark 20\n");
      break;

    case >= 6350 && <= 7650:
      printf("Bark 21\n");
      break;

    case >= 7600 && <= 9400:
      printf("Bark 22\n");
      break;

    case >= 9250 && <= 11750:
      printf("Bark 23\n");
      break;

    case >= 11750 && <= 15250:
      printf("Bark 24\n");
      break;
    
    default:
      printf("Frequency bin does not correspond to bark.\n");
  }

  return 0;
}