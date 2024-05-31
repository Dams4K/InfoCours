/* Fonctions pouvant aider à débuguer */

#ifndef UTILS_H
#define UTILS_H 0

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>


/* Affichage */

/** Affiche T[deb...fin[ sur la sortie standard. */
void print_array(int const* T, int deb, int fin);


/* Vérificateurs de tris */


/** Vérifie si T[deb...fin[ est trié.
    Renvoie true si il est trié, et false sinon.
*/
bool est_trie(int const* T, int deb, int fin);

/** Renvoie le premier indice i tel que T[i] > T[i+1].
    Ne cherche cela que dans T[deb...fin[.
    S'il n'y a pas de tel i, renvoie -1.
*/
int indice_inversion(int const* T, int deb, int fin);


/* Génération de tableaux aléatoires */

/** Initialise l'aléatoire.
    À utiliser avant la première utilisation de l'aléatoire 
    par le programme.
    Mènera à la même suite d'aléas si utilisé deux fois dans la même seconde.
*/
void initialise_rand(void);

/** Renvoie un entier aléatoire de [a;b].
    Suit une loi à peu près uniforme.
*/
int randint(int a, int b);

/** Génère un tableau de n entiers aléatoires de [a;b].
    Suit à peu près une loi uniforme.
    Le tableau renvoyé est alloué et doit être libéré avec free après usage. */
int* randarray(int n, int a, int b);


#endif