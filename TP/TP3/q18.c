#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned n = 99999;
    while (n > 1000) {
        scanf("%d", &n);
    }


    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d, ", i);
    }
    printf("%d}\n", n);
    printf("\n");


    for (int i = 0; i < n; i++) {
        printf("{");
        for (int j = i+1; j < n; j++) {
            printf("%d, ", j);
        }
        printf("%d}\n", n);
    }
    printf("\n");


    for (int i = 0; i < n; i++) {
        printf("{");
        for (int j = 0; j < n-(i+1); j++) {
            printf("%d, ", j);
        }
        printf("%d}\n", n);
    }
    printf("\n");

    return EXIT_SUCCESS;
}