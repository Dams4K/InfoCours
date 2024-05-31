#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

int main(void) {
    unsigned E[10000] = {4, 2, 3, 2, 1};
    uint8_t N = 5;
    tri(E, N);
    
    printf("[");
    for (int i = 0; i < N-1; i++) {
        printf("%d, ", E[i]);
    }
    printf("%d]\n", E[N-1]);

    return EXIT_SUCCESS;
}