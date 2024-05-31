#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 1a
int renvoie_valeur_pointee(int* ptr) {
    return *ptr;
}

double renvoie_valeur_pointee_d(double* ptr) {
    return *ptr;
}

// 1b
int somme_pointers(int* a, int* b) {
    return *a + *b;
}

// 2
void efface(int* ptr) {
    *ptr = 0;
}

// 3
void incr(int* ptr) {
    *ptr += 1;
}

// 6
void assigne(int x, int* ptr) {
    *ptr = x;
}

void echange_2t_double(double t[2]) {
    double tmp = t[0];
    t[0] = t[1];
    t[1] = tmp;
}

void echange_2p_double(double* a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void wayne(int* ptr_x, int* ptr_y) {
    *ptr_y += *ptr_x;
    *ptr_x = *ptr_y - *ptr_x;
    *ptr_y = *ptr_y - *ptr_x;
    return;
}

int main(void) {
    int x = 15;
    int y = 5;
    int* px = &x;
    int* py = &y;

    printf("%d\n", renvoie_valeur_pointee(px));
    printf("%d\n", somme_pointers(px, py));

    efface(px);
    incr(px);
    printf("%d\n", renvoie_valeur_pointee(px));

    double T[2] = {1.6, 3.2};
    echange_2t_double(T);
    printf("%lf ; %lf\n", T[0], T[1]);

    double dx = 15.0;
    double dy = 5.0;
    double* dpx = &dx;
    double* dpy = &dy;

    echange_2p_double(dpx, dpy);
    printf("x = %lf ; y = %lf\n", renvoie_valeur_pointee_d(dpx), renvoie_valeur_pointee_d(dpy));

    printf("x = %d ; y = %d\n", renvoie_valeur_pointee(px), renvoie_valeur_pointee(py));
    wayne(px, py);
    printf("x = %d ; y = %d\n", renvoie_valeur_pointee(px), renvoie_valeur_pointee(py));

    return EXIT_SUCCESS;
}
