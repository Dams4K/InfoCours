/* Implémentation de files par tableaux circulaires */

#include "file.h"

file* file_vide(int capacite) {
    assert(capacite > 0);

    file* f = (file*) malloc(sizeof(file));
    int* contenu = (int*) malloc(sizeof(int) * capacite);

    f->contenu = contenu;
    f->capacite = capacite;
    f->sortie = 0;
    f->len = 0;

    return f;
}

void file_free(file* f) {
    free(f->contenu);
    free(f);
}



bool file_est_vide(file const* f) {
    return file_len(f) == 0;
}

int file_premier(file const* f) {
    return f->contenu[f->sortie];
}

int file_len(file const* f) {
    return f->len;
}

void file_affiche(file const* f) {
    printf("<- [");
    int sortie = f->sortie;
    int end = f->sortie + f->len - 1;
    
    for (int i = sortie; i < end; i++) {
        printf("%d, ", f->contenu[i%f->capacite]);
    }

    if (f->len > 0) {
        printf("%d", f->contenu[end%f->capacite]);
    }
    printf("] <-\n");
}


void file_enfile(file* f, int x) {
    assert(file_len(f) < f->capacite);

    int index = (f->sortie+file_len(f))%f->capacite;
    f->contenu[index] = x;
    f->len++;
}

int file_defile(file* f) {
    int x = f->contenu[f->sortie];
    f->sortie++;
    f->len--;
    return x;
}


file* file_from_tab(int* tab, int n) {
    file* f = file_vide(n);
    f->len = n;

    for (int i = 0; i < n; i++) {
        file_enfile(f, tab[i]);
    }
    
    return f;
}


int* tab_from_file(file const* f) {
    int* tab = (int*) malloc(sizeof(int) * f->capacite);

    int sortie = f->sortie;
    int end = f->sortie + f->len;

    for (int i = sortie; i < end; i++) {
        tab[i-sortie] = f->contenu[i % f->capacite];
    }

    return tab;
}