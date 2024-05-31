#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned n = 99999;
    while (n > 1000) {
        scanf("%d", &n);
    }

    int T[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &T[i]);
    }

    int T2[1000];

    for (int i = 0; i < n; i++) {
        int x = T[i];
        int j = i;
        while (j > 0 && T[j-1] > x) {
            T2[j] = T[j-1];
            
            j--;
        }
        T2[j] = x;
    }

    for (int i = 0; i < n-1; i++) {
        printf("%d < ", T2[i]);
    }
    printf("%d\n", T2[n-1]);

    return EXIT_SUCCESS;
}