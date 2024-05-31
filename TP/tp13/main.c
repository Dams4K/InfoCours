#include <stdio.h>
#include <stdlib.h>

#include "tp.h"

int main(void) {
    point p0;
    p0.x = 0;
    p0.y = 1;

    point p1;
    p1.x = 2;
    p1.y = 1;

    point p2;
    p2.x = 3;
    p2.y = 2;

    point T[] = {p0, p1, p2};

    // point p_max = T[indice_pt_max(T, 2)];
    // printf("x: %d, y: %d\n", p_max.x, p_max.y);
    tri_selection(T, 3);
    for (int i = 0; i < 3; i++) {
        point p = T[i];
        printf("x: %d, y: %d\n", p.x, p.y);
    }

    return EXIT_SUCCESS;
}