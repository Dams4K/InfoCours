#include "tas-classique.h"

void affiche_tas(tas t) {
    for (int i = 0; i < t.n; i++) {
        printf("%d ", t.T[i]);
    }
    printf("\n");
}

tas tas_vide() {
    return (tas) {.T = {}, .n = 0};
    // tas* t = malloc(sizeof(tas));
    // t->n = 0;
    // return t;
}

bool est_vide(tas t) {
    assert(t.n > 0); // Le tas est vide
    return t.T[0];
}

void main() {
    tas t = {.T = {1, 8, 7, 14, 13, 20}, .n = 6};
    affiche_tas(t);
}