#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct tas_s {
    int T[10000]; //tableau statique représentant le tas (pas besoin de l'allouer !)
    int n; //nombre de sommets du tas (taille réelle du tableau)
};
typedef struct tas_s tas;


//Crée un tas vide.
tas tas_vide(void);

//Insère un élément entier prio dans le tas t.
void insere(tas* t, int prio);

//Extrait le minimum du tas t. MODIFIE le tas.
int extrait_min(tas* t);

//Renvoie le minimum du tas t, SANS modifier le tas.
int lit_min(tas t);

//Teste si le tas est vide.
bool est_vide(tas t);