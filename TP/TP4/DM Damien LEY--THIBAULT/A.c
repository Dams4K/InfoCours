// Damien LEY--THIBAULT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Q1.a
bool est_stockable(unsigned L, unsigned N, unsigned E[10000]) {
    unsigned sum = 0;

    for (unsigned i = 0; i < N; i++) {
        sum += E[i];
    }

    return sum <= L;
}

// Q2
bool sf_est_stockable(unsigned L, unsigned N, unsigned E[10000], bool J[10000]) {
    unsigned sum = 0;

    for (unsigned i = 0; i < N; i++) {
        if (J[i]) {
            sum += E[i];
        }
    }

    return sum <= L;
}

//Q4.a
unsigned bibli_opti_triee(unsigned L, unsigned N, unsigned E[10000]) {
    unsigned J = 0;
    while (est_stockable(L, J+=1, E) && J <= N);
    return J-1;
}


int main(void) {
    unsigned N = 4;
    unsigned E[10000] = {5, 3, 8, 9};
    bool J[10000] = {1, 0, 0, 1};

    printf("est_stockable: %d\n", est_stockable(14, N, E));
    printf("sf_est_stockable: %d\n", sf_est_stockable(14, N, E, J));

    unsigned E2[10000] = {3, 5, 6, 9};
    printf("taille max: %d\n", bibli_opti_triee(14, N, E2));

    return EXIT_SUCCESS;
}