// Damien LEY--THIBAULT
#include <stdio.h>
#include <stdlib.h>


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
    unsigned T[10000] = {5, 6, 6, 3, 4, 1, 8, 9, 9, 10, 2};
    unsigned N = 11;
    tri_denomb(T, N);

    printf("[");
    for (unsigned i = 0; i < N-1; i++) {
        printf("%d, ", T[i]);
    }
    printf("%d]\n", T[N-1]);
    return EXIT_SUCCESS;
}
