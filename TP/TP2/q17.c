#include <stdio.h>
#include <stdlib.h>

void bin_to_hex(int8_t dec_hexa[8], int8_t dec_bin[32]) {
    for (int i = 0; i  < 8; i++) {
        int f = 1;
        int hex = 0;

        for (int j = 3; j >= 0; j--) {
            int idx = (i*4)+j;
            hex += f*dec_bin[idx];
            
            printf("%d*%d + ", f, dec_bin[idx]);

            if (f == 1) {
                f = 2;
            } else {
                f *= 2;
            }
        }
        printf("= %d\n", hex);
        
        dec_hexa[i] = hex;
    }
}

void main() {
    int8_t hexa[8];
    int8_t bin[32] = {
        0, 1, 0, 0,
        0, 0, 1, 1,
        0, 0, 0, 1,
        1, 1, 0, 1,
        0, 0, 0, 1,
        1, 1, 1, 0,
        0, 0, 1, 0,
        0, 1, 1, 1
    };
    
    // int8_t bin[32] = {
    //     0, 0, 0, 0,
    //     0, 0, 0, 0,
    //     0, 0, 0, 0,
    //     0, 0, 0, 0,
    //     0, 0, 0, 0,
    //     0, 0, 0, 0,
    //     0, 0, 0, 0,
    //     0, 0, 1, 0
    // };

    bin_to_hex(hexa, bin);

    for (int i = 0; i < 8; i++) {
        printf("%x", hexa[i]);
    }
    printf("\n");
}