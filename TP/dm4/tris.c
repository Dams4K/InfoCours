/* Implémentations d'algorithmes de tri */

#include "tris.h"


/* Pré-codés */

void tri_bulle(int* T, int deb, int fin) {
  for (int nb = 0; nb < fin-deb; nb+=1) {
    for (int i = deb; i+1 < fin; i+=1) {
      if (T[i] > T[i+1]) {
        int tmp = T[i];
        T[i] = T[i+1];
        T[i+1] = tmp;
      }
    }
  }
  return;
}

/** Comparaison d'entiers pour qsort */
int cmp(void const* a, void const* b) {
  return *(int*)a - *(int*)b;
}

void tri_rapide_stdlib(int* T, int deb, int fin) {
  qsort((void*) &T[deb], (size_t) (fin-deb), sizeof(int), &cmp);
  return;
}



/* Tri Fusion : TODO, à vous de jouer ! */


void fusion(int* arr, int p, int q, int r) {
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}


void tri_fusion(int* T, int deb, int fin) {
  if (deb < fin) {

    // m is the point where the array is divided into two subarrays
    int m = deb + (fin - deb) / 2;

    tri_fusion(T, deb, m);
    tri_fusion(T, m + 1, fin);

    // Merge the sorted subarrays
    fusion(T, deb, m, fin);
  }
}



/* Tri Rapide : TODO, à vous de jouer ! */

void permuter(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void tri_rapide(int* tab, int deb, int fin) {
    int pivot, i, j;
    if(deb < fin) {
        pivot = deb;
        i = deb;
        j = fin;
        while (i < j) {
            while(tab[i] <= tab[pivot] && i < fin)
                i++;
            while(tab[j] > tab[pivot])
                j--;
            if(i < j) {
                permuter(&tab[i], &tab[j]);
            }
        }
        permuter(&tab[pivot], &tab[j]);
        tri_rapide(tab, deb, j - 1);
        tri_rapide(tab, j + 1, fin);
    }
}