#include <stdio.h>

void pascal(int n) {
    n++; // :)
    
    int t_size = 1;
    int t[n];
    t[0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < t_size; j++) {
            printf("%d ", t[j]);
        }
        printf("\n");

        t_size += 1;
        t[t_size-1] = 1;

        int new_t[t_size];
        new_t[0] = 1;
        new_t[t_size-1] = 1;
        for (int j = 1; j < t_size-1; j++) {
            new_t[j] = t[j-1] + t[j];
        }

        for (int j = 0; j < t_size; j++) {
            t[j] = new_t[j];
        }
    }
}

void main() {
    pascal(4);
}