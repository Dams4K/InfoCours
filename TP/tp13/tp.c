#include "tp.h"

bool greater(point p0, point p1) {
    return p0.y < p1.y || p0.y == p1.y && p0.x < p1.x;
}

int indice_pt_max(point T[], int n) {
    int max_p_i = 0;

    for (int i = 0; i < n; i++) {
        if (greater(T[i], T[max_p_i])) {
            max_p_i = i;
        }
    }
}

void tri_selection(point T[], int n) {
    for (int i = 0; i < n-1; i++) {
        int indice = indice_pt_max(T, i);
        int tmp = T[i-1];
        T[i-1] = T[indice];
        T[indice] = tmp;
    }
}