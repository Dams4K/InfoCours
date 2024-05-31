/* Fichier permettant de tester test.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "file.h"


// Ignorez cette déclaration de fonction pour l'instant.
int* lecture(char const* filename, int* n);


// Le main. Ignorez ses arguments pour l'instant.
int main(int argc, char const* argv[]) {
  /* Ne pas décommenter avant que l'énoncé ne vous le dise */
  if (argc == 1) { printf("Aucun fichier cantine à lire.\n"
                          "Pour en donner un, faire : "
                          "%s nomdufichiercantine.txt\n", argv[0]); 
  }
  

  /* TODO : Mettez vos tests juste ici. */
  

  file* f = file_vide(3);
  file_affiche(f);

  file_enfile(f, 5);
  file_affiche(f);


  file_enfile(f, 7);
  file_affiche(f);

  printf("défile %d\n", file_defile(f));

  file_enfile(f, 70);
  file_enfile(f, 85);
  file_affiche(f);

  int* tab = tab_from_file(f);
  for (int i = 0; i < f->capacite; i++) {
    printf("%d ", tab[i]);
  }
  printf("\n\n");


  file_free(f);


  /* Idem, ne pas décommenter avant que l'énoncé ne vous le dise */
  if (argc >= 2) { 
    printf("Le fichier %s sera utilisé comme fichier cantine.\n", argv[1]);
    int n = 0;
    int* mouv = lecture(argv[1], &n);
    // mouv contient maintenant le tableau correspondant à la queue de la cantine.
    // Vous devez vérifier si elle est valide ou non (i.e. si personne n'a doublé, et si tout le monde qui est entré dans la queue a mangé).
    
    bool a_double = false;
    file* queue = file_vide(n);
    for (int i = 0; i < n; i++) {
      if (mouv[i] == 0) continue;
      
      if (mouv[i] > 0) {
        file_enfile(queue, mouv[i]);
      } else {
        int x = file_defile(queue);

        a_double = a_double || mouv[i] + x != 0; 
      }
    }

    if (a_double) {
      printf("A doublé\n");
    } else {
      printf("N'a pas doublé\n");
    }
    // file* queue = file_from_tab(mouv, n);

    // file_affiche(queue);

    free(mouv);
  }

  return EXIT_SUCCESS;
}






/******************************************************************/
// IGNOREZ CETTE ZONE AVANT D'AVOIR FINI DE CODER LES FILES 

/** Lit un fichier contenant une description des mouvements de queue de cantine.
    Un tel fichier contient :
    - sur sa première ligne, le nombre de mouvements
    - sur sa ligne suivante, séparés par des espaces, les entrées/sorties
  
  Cette fonction renvoie renvoie un pointeur vers une zone contenant tous les entiers des entrées/sortis. Elle modifie le contenu pointé par, mais modifie ce qui est pointé par n de sorte à ce que ce qu'il soit le nombre d'élèves entrants/sortants
  */
int* lecture(char const* filename, int* n) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Le fichier %s n'a pas pu être ouvert.\n", filename);
    exit(EXIT_FAILURE);
  }

  fscanf(fp, " %d\n", n); // lecture de la première ligne
  int* mouv = (int*) malloc( (*n) * sizeof(int) );
  for (int i = 0; i < *n; i+=1) { // lecture des entiers de la ligne suivante
    fscanf(fp, " %d", &(mouv[i]));
  }
  
  fclose(fp);
  return mouv;
}

// FIN DE LA ZONE À IGNORER
/******************************************************************/
