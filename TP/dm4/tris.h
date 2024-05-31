/* Des algortihmes de tri */

#ifndef TRIS_H
#define TRIS_H

#include <stdlib.h>

/* Tris pré-codés */

/** Trie T[deb...fin[ en utilisant un tri bulle.
    Complexité temporelle : O(n²).
    Complexité spatialle : O(1).
    
    Rappel : c'est un des tris les plus simples,
    mais aussi un des moins efficaces.
*/
void tri_bulle(int* T, int deb, int fin);

/** Trie T[deb...fin[ en utilisant quicksort,
    çad le tri rapide de stdlib.h .
*/
void tri_rapide_stdlib(int* T, int deb, int fin);


/* Tris que vous devez coder : TODo */

/** Trie T[deb...fin[ par tri fusion */
void tri_fusion(int* T, int deb, int fin);

/** Trie T[deb...fin[ par tri rapide*/
void tri_rapide(int* T, int deb, int fin);


#endif