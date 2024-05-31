#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

int chaine_longueur(char const* texte) {
    int i = 0;
    while (texte[i]) { // `\0` est évalué à false
        i++;
    }
    return i;
}

bool inf_lexico(char const* mot_gauche, char const* mot_droite) {
    int i = 0;
    while (mot_gauche[i] || mot_droite[i]) {
        if (mot_gauche[i] == mot_droite[i]) {
            i++;
            continue;
        }
        
        return mot_gauche[i] < mot_droite[i];
    }

    return chaine_longueur(mot_gauche) < chaine_longueur(mot_droite);
}

int main(void) {
    char* texte = "Mon beau texte";
    printf("%d\n", chaine_longueur(texte));
    
    printf("%d\n", inf_lexico("bac", "bad"));

    return EXIT_SUCCESS;
}