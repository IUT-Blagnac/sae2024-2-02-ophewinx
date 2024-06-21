#include "RLE.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
  char in[100];

  if (argc > 1) {
    strcpy(in, argv[1]);
  } else {
    printf("Chaine a transformer : ");
    scanf("%s", in);
  }

  printf("Entree : %s\n", in);

  struct timespec start, end;

  clock_gettime(CLOCK_MONOTONIC, &start);

  char *output = RLE_recursive(in,3);

  clock_gettime(CLOCK_MONOTONIC, &end);

  printf("Sortie : %s\n", output);

  double durationMillis = (end.tv_sec - start.tv_sec) * 1000.0 +
                          (end.tv_nsec - start.tv_nsec) / 1000000.0;

  printf("Temps d'execution : %.3f ms\n", durationMillis);

  free(output);

  runTests();

  return 0;
}
