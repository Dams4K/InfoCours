M: (i, j)

si i = j<br>
| renvoyer 0<br>
sinon<br>
| p_opt = +oo<br>
| boucle k de i à j<br>
| | s = M(i, k) + M(k+1, j) + m_i * m_k * m_j<br>
| | si s < p_pot<br>
| | | p_opt = s

| return p_opt


```
M_mémo(i,j,mem):
    si i = j:
        return 0
    sinon:
        opt <- int_max
        
```


Exercice 4 algo gloutons
```C
void gl(int books[], int bl, int L, bool G[]) {
    int current_l = 0;
    int current_idx = 0;
    while (current_l < L && current_idx < bl) {
        G[current_idx] = true;
        current_idx += 1;
        current_l += books[current_idx];
    }
}

void gl2(int const a[], int n, int L, bool G[]) {
    // pré-conditions: a trié par ordre croissant; G init à false
    int poid_tot = 0;
    for (int i = 0; i < n; i++) {
        if (poid_tot + a[i] <= L) {
            G[i] = true;
            poid_tot += a[i];
        } else {
            break;
        }
    }
}
```

On suppose les a_i croissant

Lemme d'échange: mq'il existe une solution optimale contenant F_0

Soit S une solution optimale au problème

S = {F_i0, F_i1, ..., F_ij}

1) Si F_0 € S: trivial
2) Si F_0 n'appartient pas à S, on a:

$\sum^{j}_{k=0}{a_{ik}} \leq L => a_{i0} + \sum^{j}_{k=1}{a_{ik}} \leq L$ or $a_{i0} > a_0$

Donc $a_{0} + \sum^{j}_{k=1}{a_{ik}} \leq L$. S' = {F_0, ..., F_ij} est une solution et S' est optimale car |S'| = S

Une instance I du problm est la donnée de:
- les poids a_0, ..., $a_{n-1}$
- n
- L

Raisonnons par récurrence sur n le nombre de fichiers

**Initialisation:** n=0 ou L < a_0:

Toute solutions est $\empty$. Le glouton renvoie $\empty$. Alors le glouton renvoie une solution optimale

**Hérédité**: Soit n € **N***

Supposons que l'algorithme renvoie une solution optimale pour tout m < n prtt L' < L

Soit I une instance à n fichiers. D'après le lemme d'échange, il existe une solution optimale S de la forme S = {F_0, F_i0, ..., F_ij}. Posons S = {F_0} U S'. On a:

$\sum^{j}_{n=0}{a_{ik}} \leq L-a_0$ donc S' est solution de I': *trop de truc bizarres*

Or par HR, I' admet G' une solution optimale qui utilise l'algorithme glouton. On a |G'| $\geq$ |S'|

$a_0 + \sum_{F_k € G'}{a_k} \leq L$ donc G = {F_0} U G' est une solution de I

|G| = 1 + |G'| $\geq$ 1 + |S'| = |S| qui est optimale

**Conclusion**: L'algorithme glouton renvoie toujours une solution optimale




**Exercice 4 :**

2) ```
|-------|   |-------|
           |-----|
       |----|            |-----|
````