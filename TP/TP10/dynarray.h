#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#ifndef DYNARRAY_H
#define DYNARRAY_H 0

struct dynarray_s {
 int* tab; // pointeur vers les cases du tableau dynamique
 int n;    // nombre de cases du tableau (utilisées ou non)
 int len;  // nombre de cases utilisées du tableau
};
typedef struct dynarray_s dynarray;

/* moi */
uint64_t puiss_2(int n);

/* Création, conversion, suppression */

/** Crée un tableau dynamique de longueur len initialisé à x.*/
dynarray* dyn_create(int len, int x);

/** Supprime un tableau dynamique */
void dyn_free(dynarray* a);

/** Crée un tableau dynamique qui contient les valeurs d'un tableau/zone allouée */
dynarray* dynarray_of_array(int len, int T[]);

/** Crée une zone allouée contenant les valeurs d'un tableau dynamique */
int* array_of_dynarray(dynarray const* a);


/* Accès et modifications */

/** Accès à l'élément d'indice i d'un tableau dynamique */
int dyn_acces(dynarray const* a, int i);

/** Remplace par x l'élément d'indice i d'un tableau dynamique */
void dyn_remplace(dynarray* a, int i, int x);

/** Ajoute un élément x dans un tableau dynamique a.*/
void dyn_ajoute(dynarray* a, int x);

/** Enlève un élément du tableau dynamique a (doit être non vide).*/
int dyn_retire(dynarray* a);


/* Misceleanous */

/** Renvoie le nombre d'éléments d'un tableau dynamique */
int dyn_len(dynarray const* a);

/** Affiche un tableau dynamique */
void dyn_affiche(dynarray const* a);

#endif
