/* Implémentation de diverses fonctions aidant à débuguer */

#include "utils.h"


/* Affichage */

/** Affiche T[deb...fin[ sur la sortie standard. */
void print_array(int const* T, int deb, int fin) {
  printf("tableau[%d...%d[ : |", deb, fin);
  for (int i = deb; i < fin; i+=1) {
    printf(" %d |", T[i]);
  }
  printf("\n");
  return;
}


/* Vérificateurs */

/** Vérifie si T[deb...fin[ est trié. */
bool est_trie(int const* T, int deb, int fin) {
  return indice_inversion(T, deb, fin) == -1;
}

/** Renvoie le premier indice i tel que T[i] > T[i+1].
    Ne cherche cela que dans T[deb...fin[.
    S'il n'y a pas de tel i, renvoie -1.
*/
int indice_inversion(int const* T, int deb, int fin) {
  for (int i = deb; i+1 < fin; i+=1) {
    if (T[i] > T[i+1]) { return i; }
  }
  return -1;
}


/* Génération aléatoire */

/** Initialise l'aléatoire. */
void initialise_rand(void) {
  srand((unsigned) time(NULL));
  return;
}

/** Renvoie un entier aléatoire de [a;b]. */
int randint(int a, int b) {
  return rand() % (b-a+1) + a;
}

/** Génère un tableau de n entiers aléatoires de [a;b]. */
int* randarray(int n, int a, int b) {
  int* array = (int*) malloc(n*sizeof(int));
  for (int i = 0; i < n; i+=1) { array[i] = randint(a,b); }
  return array;
}