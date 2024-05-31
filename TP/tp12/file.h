/* Module implémentant des files bornées */

#ifndef FILE_H
#define FILE_H 0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


struct file_s {
  int* contenu;    // le tableau circulaire
  int capacite; // le nb max d'elem de la file
  int sortie;      // l'indice du prochain élément à sortir
  int len;      // le nombre d'éléments dans la file
};
typedef struct file_s file;

/* Initialisateurs : création, suppression */

/** Crée une file vide de capacité maximale capacite */
file* file_vide(int capacite);

/** Supprime une file */
void file_free(file* f);


/* Accesseurs */

/** Teste si une file est vide */
bool file_est_vide(file const* f);

/** Renvoie le prochain élément à sortir de la file, sans le défiler */
int file_premier(file const* f);

/** Renvoie le nb d'éléments d'une file */
int file_len(file const* f);

/** Affiche les éléments d'une file dans l'ordre */
void file_affiche(file const* f);


/* Transformateurs */

/** Enfilage d'un élément x dans la file */
void file_enfile(file* f, int x);

/** Défile la file, et renvoie l'élément défilé */
int file_defile(file* f);

file* file_from_tab(int* tab, int n);
int* tab_from_file(file const* f);

#endif