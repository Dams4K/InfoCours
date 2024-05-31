#include <stdio.h>

void main() {
    int x;
    scanf("%d", &x);

    if (x <= 0) {
        printf("Non parfait\n");
        return;
    }

    int sum = 0;
    for (int i = 1; i <= x; i++) {
        if (x%i == 0) {
            printf("%d; ", x/i);
            sum += x/i;
        }
    }
    printf("\n");

    printf("%d, %d; ", sum/2, x);
    if (x == sum/2) {
        printf("Nombre parfait");
    } else  {
        printf("Nombre non-parfait");
    }
    printf("\n");
}