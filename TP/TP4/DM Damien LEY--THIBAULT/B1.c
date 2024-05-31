// Damien LEY--THIBAULT
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void bullage(unsigned T[10000], unsigned N) {
    for (unsigned i = 0; i < N-1; i++) {
        if (T[i+1] < T[i]) {
            unsigned tmp = T[i];
            T[i] = T[i+1];
            T[i+1] = tmp;
        }
    }
}

// Q5.a
void tri(unsigned T[10000], unsigned N) {
    for (unsigned i = 0; i < N; i++) {
        bullage(T, N);
    }
}

int main(void) {
    unsigned E[10000] = {4, 2, 3, 2, 1};
    unsigned N = 5;
    tri(E, N);
    
    printf("[");
    for (unsigned i = 0; i < N-1; i++) {
        printf("%d, ", E[i]);
    }
    printf("%d]\n", E[N-1]);

    return EXIT_SUCCESS;
}