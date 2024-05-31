#include <stdio.h>
#include <stdlib.h>

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

int main(void) {
    unsigned E[10000] = {4, 2, 3, 2};
    unsigned N = 4;

    int taille_max = blibli_opti(8, N, E);

    printf("Taille max bibli_opti: %d\n", taille_max);

    return EXIT_SUCCESS;
}