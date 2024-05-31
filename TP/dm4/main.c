#include <stdio.h>
#include <stdlib.h>

#include "tris.h"
#include "utils.h"


int main(void) {

  initialise_rand();
  
  /* Génère un tableau aléatoire et le trie, puis teste si il est trié. */
  int n = 100;
  int* T = randarray(n, 0, 256);
  // tri_bulle(T, 0, n);
  for (int i = 0; i < 1000000; i++) {
    T = randarray(n, 0, 256);
    tri_fusion(T, 0, n);
  }
  print_array(T, 0, n);
  if (est_trie(T, 0, n)) {
    printf("Ce tableau est trié.\n");
  } else {
    printf("Ce tableau n'est pas trié.\n");
  }

  return EXIT_SUCCESS;
}