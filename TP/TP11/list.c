/** Implémentation de listes simplement chainées */

#include "list.h"
#include <stdbool.h>

/* La liste vide. */
cellule const* vide = NULL;

cellule* list_create(int x) {
    cellule* cell = (cellule*) malloc(sizeof(cellule));
    cell->elem = x;
    cell->next = vide;

    return cell;
}

void cellule_free(cellule* p) {
    free(p);
}

void list_free(cellule* p) {
    if (p == vide) return;

    list_free(p->next);
    cellule_free(p);
}

int list_hd (cellule const* p) {
    return p->elem;
}

cellule* list_tl(cellule const* p) {
    return p->elem;
}

size_t list_size(cellule const* p) {
    if (p == vide) {
        return 0;
    }

    return 1+list_size(p->next);
}


bool list_mem(int x, cellule const* p) {
    if (p == vide) return false;
    return p->elem == x || list_mem(x, p->next);
}


void print_list(cellule const* p) {
    cellule* current_cell = p;
    printf("[");
    while (current_cell->next != vide) {
        printf("%d, ", current_cell->elem);

        current_cell = current_cell->next;
    }
    printf("%d]\n", current_cell->elem);
}


cellule* list_cons(int x, cellule const* p) {
    cellule* new_cell = (cellule*) malloc(sizeof(cellule));
    new_cell->elem = x;
    new_cell->next = p;

    return new_cell;
}


int get_cell(int index, cellule const* p) {
    if (p == vide) {
        return -1;
    }
    if (index == 0) {
        return p->elem;
    }
    return get_cell(index-1, p->next);
}

cellule* array_to_cellule(int len, int T[]) {
    if (len == 1) {
        return list_create(T[0]);
    }
    return list_cons(T[len-1], array_to_cellule(len-1, T));
}