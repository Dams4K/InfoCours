# I - Généralités

On veut résoudre des prblm d'opt, çàd des prblm qui demandent de cstr une solution à partir de plrs "briques" tq la sol soit optimale

> [!NOTE]
> Ex:
> - Trouver le + lourd chemin dans une pyramide:
> suite de choix g/d qui doit maximiser la somme des noeuds
> - rendu de monnais: on veut rendre s€N. On a accès à des pièces dont la valeur est donnée par l'ens S (ex: S = {1, 2, 5})
>
> On peut utiliser autant de chq pièces que l'on veut. Comment utiliser le moins de pièces possible?
>
> Ex: s=23, S={1; 2; 5}<br>
> 5+5+5+5+2+1: 6 pièces<br>
> 5+5+5+5+1+1+1: 7 pièces<br>

Méthode de la résolution gloutonne:
- décomposer la cstr d'une sol ĉ suite de choix
- cstr la sol graduellement en partant de "aucun choix effectué" chq choix successif est fait pour optimiser un critère local et simple. On ne remet jamais en question les choix préc

Ex: dans la pyramide, aller à g ou à d selon si le noeud g ou d est le plus lourd.

-> Cet algo ne donne pas une sol opt

Autre essai algo glouton qui fait g/d pour se rapporcher du max de la pyramide

pas de schéma

Ex: sur le rendu de monnaie:

rendre la + grosse pièce possible jsq'à avoir tout rendu

- S = {1, 2, 5}: sur ce systeme, glouton est optimal

- S = {1, 7, 8}: Pour rendre 14, l'algo rend 8 (reste 6) puis 1 1 1 1 1 1 1 soit 7 pièces<br>alors que 14 = 7+7

# II - Ex fil rouge: l'ordonnancement d'intervalles


Prblm du gymnase organise une journée de découvertes des sports

Cependant, une seule activité peut avoir lieu à la fois

Chq activité demande un créneau horaire ]début; fin[ précis. comment permettre le + d'activités


Ex des demandes

flemmes de faire le schéma, c'est des plages horaires où certaines se mangent dessus ce qui fait qu'on ne peut pas les mettre derrières les autres


Formellement, on a un ensemble R de n requêtes r0, r1, ..., r_n+1.

Chq requête est un intervalle ouvert r_i = ]d_i, f_i[

On veut trouver un plus grand (en nb d'intervalles) sous-ens de R dont les intervalles st 2 à 2 disjoints

On parle d'ordonnancement d'intervalles (Interval Scheduling)

Ex d'algo glouton:
- prendre l'intervalle qui commence en 1er (parmi ceux qui n'inters pas ceux déjà pris)

Contre exemple:

```
|----------------------------------|
  |-| |-| |-| |-| |-| |-| |-| |-| 
```

- prendre l'intervalle qui $\cap$ le moins d'autres intervalles

```
    |--|      |---|
    |--|      |---|
    |--|      |---|
    |--|      |---|
|----||--||----| |--------|
        |--|
```

- prendre les + pt (en longueur) en priorité

contre-ex:
```
|---------------| |------| |---------|
              |----|    |----|
```

- prendre ceux qui terminent le + tôt en 1er

=> optimal

### a. Schéma général de preuve de correction

On veut résoudre une instance I d'un prblm.

On procède en 2 temps:
1) il existe une solution optimal de l'instance qui débute par le 1ier choix glouton (lemme d'échange)

2) On prouve ensuite par récurrence sur la taille de l'instance que la solution gloutonne est optimale.

    **Initialisation :** ras

    **Héréd :** par lemme d'échange il existe S_opt = {g_o, s_1, s_2, ...}

    une solution optimale débutant par le 1ier choix glouton.

    On note I' l'instance obtenue à partir de I en "enlevant les choix incompatibles avec g_o". Donc "I' < I''" On a donc S' = {s_1, s_2, ...} qui est une solution de I'. Or, glouton est opt sur I' (H.R.), nommons {g_1, g_2, ...} sa sortie.

    Donc {g_1, g_2, ...} est meilleur que {s_1, s_2, ...}

    Donc G = {g_0, g_1, ...} est meilleur que Sopt donc G est opt.

### b. Ex sur Interv. Scheduling

Cf preuve annexe

```
|-r0-|        |-------| |----ri2--|
    |-------------|  |------|
 |--ri0-|       |--ri1-|
```

On doit donc mq r_0 n' $\cap$ pas les $r_{ij}$ pour j >= 1, ie f_0 <= $d_{ij}$ pour j >= 1

Or, les $r_{ij}$ n'$\cap$ pas r_i_0

Donc $d_{ij}$ >= f_{i0} >= f_0

NB: ici, "pas d'$\cap$" a été traduit en "commencer après la fin"

Il faudrait aussi traiter "terminer avant le début", Donc {r_0, r_i1, ...} est une solution de meme card que {r_i0, ...} donc solution optimate.


> [!CAUTION]
> **Rmq**<br>
> - pour prouver le lemme d'échange, on a échangé le 1er élem d'une sol opti avec le 1er choix glouton: d'où le nom.
>
>   c'est une façon commune de procéder
>
> - le lemme d'échange n'est pas suffisant: on veut mq la suite de choix gloutons reste opt, pas uniq le 1er

Complexité de ce glouton:

Algo:
- on lit les $\cap$ par date de fin croissant
- on prend un intervalle s'il n'$\cap$ pas le dernier choisi

- O(n) si déjà trié
- O(nlogn) sinon (on trie d'abord)

# III - Au-delà de la non-correction

Les algos gloutons sont rarement opt. Par contre ils sont:
- simples
- rapides, économes en mémoire
- parfois, même s'ils ne sont pas opt, leur ratio avec l'opt est formé. Par ex, pour un prblm de maximisation, on peut parfois mq glouton >= optimal

  On parle alors que $\lambda$-approx (cf MPI)


