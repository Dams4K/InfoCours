#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


struct paire {
    int x;
    int y;
};

struct paire division_euclidienne(int a, int b) {
    assert(b != 0);
    
    struct paire result;
    result.x = a/b;
    result.y = a%b;

    return result;
}

int main(void) {
    division_euclidienne(5, 6);

    return EXIT_SUCCESS;
}
