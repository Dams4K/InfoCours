/** Librairie de manipulation de lists*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct cellule_s {
  int elem;
  struct cellule_s* next;
};
typedef struct cellule_s cellule;


/* Constructeurs */

/** La constante liste vide 
    (le motclef extern est hors-programme.) */
extern cellule const* vide;

/** Crée une liste contenant uniquement l'élement x */
cellule* list_create(int x);

/** Désalloue une cellule (et seulement la cellule pointée) */
void cellule_free(cellule* p);

/** Désalloue toute une liste */
void list_free(cellule* p);


/* Accesseurs */

/** Renvoie l'élément de tête de liste */
int list_hd (cellule const* p);

/** Renvoie un pointeur vers la queue d'une liste */
cellule* list_tl(cellule const* p);

/** Renvoie le nombre d'éléments d'une liste */
size_t list_size(cellule const* p);

/** Teste l'appartenance d'un élément à une list */
bool list_mem(int x, cellule const* p);

/** Affiche récursivement tout une liste */
void print_list(cellule const* p);


/** Transformateurs */

/** Ajoute un élément en tête de list
    et renvoie un pointeur vers cette nouvelle tête*/
cellule* list_cons(int x, cellule const* p);

int get_cell(int index, cellule const* p);

cellule* array_to_cellule(int len, int T[]);