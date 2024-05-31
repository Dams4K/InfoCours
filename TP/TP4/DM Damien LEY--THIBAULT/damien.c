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

// Q6.a
void tri(unsigned T[10000], unsigned N) {
    unsigned i = 0;

    while (i < N) {
        unsigned e = T[i];

        int j = i;
        while (j > 0 && T[j-1] > e) {
            T[j] = T[j-1];
            j--;
        }

        T[j] = e;

        i++;
    }
}

unsigned blibli_opti(unsigned L, unsigned N, unsigned E[10000]) {
    tri(E, N);

    unsigned size = 0;
    unsigned sum = 0;

    unsigned i = 0;
    while (i < N && sum + E[i] <= L) {
        size += 1;

        i++;
        sum += E[i];
    }

    return size;
}

void tri_denomb(unsigned T[10000], unsigned N) {
    unsigned m = 0;
    unsigned M = 20000;
    unsigned Compte[20000+1] = {};

    for (unsigned i = 0; i < N; i++) {
        unsigned val = T[i];
        Compte[val] = Compte[val]+1;
    }

    unsigned i = 0;
    for (unsigned val = m; val <= M; val++) {
        for (unsigned j = 0; j < Compte[val]; j++) {
            T[i] = val;
            i++;
        }
    }
}


int main(void) {
    unsigned E[10000] = {4, 2, 3, 2, 1};
    unsigned N = 5;
    bool J[10000] = {1, 0, 0, 1, 1};

    printf("est_stockable: %d\n", est_stockable(14, N, E));
    printf("sf_est_stockable: %d\n", sf_est_stockable(14, N, E, J));

    unsigned E2[10000] = {3, 5, 6, 9};
    printf("taille max: %d\n", bibli_opti_triee(14, N, E2));

    tri(E, N);
    
    printf("[");
    for (unsigned i = 0; i < N-1; i++) {
        printf("%d, ", E[i]);
    }
    printf("%d]\n", E[N-1]);

    unsigned T[10000] = {5, 6, 6, 3, 4, 1, 8, 9, 9, 10, 2};
    unsigned N2 = 11;
    tri_denomb(T, N2);

    printf("[");
    for (unsigned i = 0; i < N2-1; i++) {
        printf("%d, ", T[i]);
    }
    printf("%d]\n", T[N2-1]);

    return EXIT_SUCCESS;
}