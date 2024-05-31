#include <stdlib.h>
#include "list.h"

int main(void) {
    cellule* cell = list_create(5);
    print_list(cell);
    cell = list_cons(15, cell);

    print_list(cell);
    printf("taille: %d\n", list_size(cell));

    if (list_mem(5, cell)) {
        printf("dedans\n");
    } else {
        printf("pas dedans\n");
    }


    if (list_mem(25, cell)) {
        printf("dedans\n");
    } else {
        printf("pas dedans\n");
    }

    printf("%d\n", get_cell(0, cell));
    printf("%d\n", get_cell(1, cell));
    printf("%d\n", get_cell(2, cell));

    list_free(cell);

    int T[5] = {0, 1, 2, 3, 4};
    print_list(array_to_cellule(5, T));

    return EXIT_SUCCESS;
}
