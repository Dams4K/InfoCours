#include "dynarray.h"
#include <assert.h>


/* Création, conversion, suppression */

uint64_t puiss_2(int n) {
    // si n = 15, première puissance de 2 supérieure : 16
    uint64_t e = 1;

    while (e < n) {
        e *= 2;
    }

    return e;
}


dynarray* dyn_create(int len, int x) {
    dynarray* arr = (dynarray*) malloc(sizeof(dynarray));

    uint64_t n = puiss_2(len);
    int* tab = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < len; i++) {
        tab[i] = x;
    }
    
    arr->n = n;
    arr->len = len;
    arr->tab = tab;

    return arr;
}


void dyn_free(dynarray* a) {
    free(a->tab);
    free(a);
}


/* Accès et modifications */

int dyn_acces(dynarray const* a, int i) {
    assert(i < a->len);
    return a->tab[i];
}


void dyn_remplace(dynarray* a, int i, int x) {
    assert(i < a->len);
    a->tab[i] = x;
}


void dyn_ajoute(dynarray* a, int x){
    if (a->len == a->n) { // Tout le tab est rempli
        uint64_t n = puiss_2(a->len+1);
        int* tab = (int*) malloc(n * sizeof(int));

        for (int i = 0; i < a->len; i++) {
            tab[i] = a->tab[i]; // On copie tout ZZzzzzz
        }

        free(a->tab); // On n'oublie pas de supprimer l'ancien tableau
        a->n = n;
        a->tab = tab;
    }
    a->tab[a->len] = x;
    a->len += 1;
}


int dyn_retire(dynarray* a){
    int idx = a->len--;
    int value = a->tab[idx];

    return value;
}


/* Miscelaneous */

int dyn_len(dynarray const* a) {
    return a->len;
}

void dyn_affiche(dynarray const* a) {
    printf("[");
    for (int i = 0; i < a->len-1; i++) {
        printf("%d, ", a->tab[i]);
    }
    printf("%d]\n", a->tab[a->len-1]);
}

int* array_of_dynarray(dynarray const* a) {
    int* tab = malloc(a->len * sizeof(int));
    for (int i = 0; i < a->len; i++) {
        tab[i] = a->tab[i];
    }
    return tab;
}

dynarray* dynarray_of_array(int len, int T[]) {
    dynarray* a = dyn_create(len, 0);
    for (int i = 0; i < len; i++) {
        dyn_remplace(a, i, T[i]);
    }
    return a;
}