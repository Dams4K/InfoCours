#include "dynarray.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


// Démo de manipulation/manipulation de tableau dynamique
dynarray* make_example() {
  int n = 8;
  int tab0[8] = {1,2,3,4,5,0,0,0};
  int* tab = malloc(n*sizeof(int));
  for (int i=0; i < n; i=i+1) {
    tab[i] = tab0[i];
  }
  dynarray* a_exemple = malloc(sizeof(dynarray));
  a_exemple->tab = tab;
  a_exemple->n = n;
  a_exemple->len = 5;
  return a_exemple;
}


int main(void) {
  dynarray* a = dyn_create(6, 42);
  printf("Longueur totale de a : %d\n", a->n);
  printf("Le tableau dynamique a contient : ");
  dyn_affiche(a);

  /* Des tests de accès et remplace */
  printf("L'élément d'indice %d est : %d\n", 2, dyn_acces(a, 2));
  dyn_remplace(a, 2, 666);
  printf("L'élément d'indice %d est : %d\n", 2, dyn_acces(a, 2));

  /* des tests d'ajouts */
  dyn_ajoute(a,1);
  printf("Le tableau dynamique a contient : ");
  dyn_affiche(a);
  dyn_ajoute(a, -20);
  printf("Le tableau dynamique a contient : ");
  dyn_affiche(a);
  dyn_ajoute(a, -58);
  printf("Le tableau dynamique a contient : ");
  dyn_affiche(a);
  dyn_ajoute(a, 39);
  printf("Le tableau dynamique a contient : ");
  dyn_affiche(a);
  printf("Après 4 ajouts, la nouvelle longueur du tableau dynamique est : %d\n", dyn_len(a));

  /* des tests de retrait */
  dyn_retire(a);
  printf("Le tableau dynamique a contient : ");
  dyn_affiche(a);
  dyn_retire(a);
  printf("Le tableau dynamique a contient : ");
  dyn_affiche(a);
  dyn_retire(a);
  printf("Le tableau dynamique a contient : ");
  dyn_affiche(a);
  dyn_retire(a);
  printf("Le tableau dynamique a contient : ");
  dyn_affiche(a);
  dyn_retire(a);
  printf("Le tableau dynamique a contient : ");
  dyn_affiche(a);
  dyn_retire(a);
  printf("Le tableau dynamique a contient : ");
  dyn_affiche(a);
  printf("Après 6 retraits, la nouvelle longueur du tableau dynamique est : %d\n", dyn_len(a));

  /* TODO : faire plus de tests !!!! */

  int* tab = array_of_dynarray(a);
  tab[1] = 0;
  dyn_affiche(a);

  int T[5] = {1, 6, 3, 45, 5};
  dynarray* a2 = dynarray_of_array(5, T);
  dyn_affiche(a2);

  dyn_free(a);
}