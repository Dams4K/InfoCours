#include <stdio.h>
#include <stdlib.h>

unsigned int* alloue_int(unsigned int init) {
    unsigned int* p = (unsigned int*) malloc(sizeof(unsigned int));
    
    *p = init;
    
    return p;
}

int main(void) {
    unsigned int* p = alloue_int(42);

    printf("%d\n", *p);

    free(p);

    return EXIT_SUCCESS;
}