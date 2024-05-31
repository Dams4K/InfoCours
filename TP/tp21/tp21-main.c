#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>



/* Je profite de ce TP pour vous présenter les arguments du main =)
   Les arguments du main permettent de lire la ligne de commande. Par
   exemple, si vous tapez : 
  		./executable alice bob 2
   le main de executable va pouvoir savoir que :
   - la ligne de commande est composée de 4 mots : "./executable", "alice", "bob", "2"
   - et accéder à chacun de ces quatre mots
   
   Le main prend deux arguments : le premier est ce nombre de mots 
   (généralement nommé argc pour ARG Count), le second ets le tableau des mots
   (généralement nommé argv pour ARG Value). Le type de ce dernier est
   un tableau de mots, donc un tableau de char*.
*/

int min(int a, int b) {
  if (a < b) return a;
  return b;
}

int max(int a, int b) {
  if (a < b) return b;
  return a;
}

int levenshtein_naif(char const* u, int i, char const* v, int j) {
  if (min(i, j) == 0) return max(i, j);
  if (u[i-1] == v[j-1]) return levenshtein_naif(u, i-1, v, j-1);

  return 1+min(
    levenshtein_naif(u, i-1, v, j),
    min(levenshtein_naif(u, i, v, j-1), levenshtein_naif(u, i-1, v, j-1))
  );
}


int lev_topdown_rec(char const* u, int i, char const* v, int j, int** mem) {
  if (mem[i][j] == -1) {
    if (min(i, j) == 0) {
      mem[i][j] = max(i, j);
    } else if (u[i-1] == v[j-1]) {
      mem[i][j] = lev_topdown_rec(u, i-1, v, j-1, mem);
    } else {
      mem[i][j] = 1+min(
        lev_topdown_rec(u, i-1, v, j, mem),
        min(lev_topdown_rec(u, i, v, j-1, mem), lev_topdown_rec(u, i-1, v, j-1, mem))
      );
    }
  }
  return mem[i][j];
}

int levenshtein_topdown(char const* u, int i, char const* v, int j) {
  int len_u = strlen(u);
  int len_v = strlen(v);

  int** mem = (int**) malloc((len_u+1) * sizeof(int*));
  
  for (int i = 0; i < len_u+1; i++) {
    mem[i] = (int*) malloc((len_v+1) * sizeof(int));
    for (int j = 0; j < len_v+1; j++) {
      mem[i][j] = -1;
    }
  }

  int d = lev_topdown_rec(u, len_u, v, len_v, mem);
  
  for (int i = 0; i < len_u; i++) {
    free(mem[i]);
  }
  free(mem);

  return d;
}

int levenshtein_bottom(char const* u, int i, char const* v, int j) {
  int len_u = strlen(u);
  int len_v = strlen(v);

  int** mem = (int**) malloc((len_u+1) * sizeof(int*));
  
  for (int i = 0; i < len_u+1; i++) {
    mem[i] = (int*) malloc((len_v+1) * sizeof(int));
    for (int j = 0; j < len_v+1; j++) {
      mem[i][j] = -1;
    }
  }

  for (int i = len_u; i >= 0; i--) {
    for (int j = len_v; j >= 0; j--) {
      if (v[i-1] == u[i-1]) continue;
      // mem[i][j] = ;
    }
  }

  for (int i = 0; i < len_u; i++) {
    free(mem[i]);
  }
  free(mem);

  return 0;
}

/** Pour utiliser l'exécutable, faire :
            ./executable premier_mot second_mot
    Votre programme va alors lire les deux mots et afficher la distance entre eux.
    Je vous ai pré-codée la lecture des mots depuis la ligne de commande.
*/
int main(int argc, char* argv[]) {
  
  // 0) Vérifier qu'il y a le bon nombre d'arguments sur la ligne de commande
  if (argc != 3) {
    printf("Utilisation : %s premier_mot second_mot\n"
           "Affiche en réponse la distance entre ces deux mots.\n",
           argv[0]);
    return EXIT_FAILURE; // notre premier exit_failure :D
  }
  
  // 1) Les lire
  char* u = argv[1];
  char* v = argv[2];
  
  // 2) À vous de jouer : calculer la distance (puis l'afficher)
  
  
  // printf("dist : %d\n", levenshtein_naif(u, strlen(u), v, strlen(v)));
  printf("dist : %d\n", levenshtein_topdown(u, strlen(u), v, strlen(v)));

  return EXIT_SUCCESS;
}

