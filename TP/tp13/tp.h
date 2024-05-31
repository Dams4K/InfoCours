#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>

struct point_s {
    int x;
    int y;
};
typedef struct point_s point;

int indice_pt_max(point T[], int n);

bool greater(point p0, point p1);

void tri_selection(point T[], int n);

#endif