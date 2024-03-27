# Graphes


Il est composé des **sommets** (ou noeuds) {1, 2, 3, ..., 12} relié ou non par des **arêtes**. Les arêtes peuvent former des **chemins** ou des **cycles**


> [!CAUTION]
> **Rmq**<br>
> Un graphe est très naturel pour repr des éléments en relation: les elems sont les sommets, et 2 elems st reliés s'ils sont en relation<br>
> On parle de str de données relationnelle.

En MP2I, on se limite à "1 arête relie 2 sommets". On peut imaginer qu'une arête relie tout un "paquet" de sommets: on parlerait d'hyperarête

- modélisation très natirelle pour les problèmes de réseaux.
- modelisation des prblm de contraintes: 2 sommets reliés st incompatibles pour une certaine contrainte

Ex: pour le prblm Interval Partionning, on peut repr les interv par des sommets et relier  intervalles s'il s'intersectent

<img src="graph_dinte.png">

Un graphe aisni obtenu est appelé graphe d'intervalle ou graphe cordal. Ils ont de bonnes pptes

et bcp bcp bcp d'autres prblm se modélisent ainsi

## I - Déf et 1ère manip

### 1. Graphes non-orentiés

> [!TIP]
> **Déf**<br>
> Un graphe nn-orienté est la donnée d'une paire (S,A) où:
> - S est un ensemble d'éléments appelés sommets
> A C= {{x, y} / x€S, y€S, y!=x}
>
> Un sommet a lui-même est un ensemble d'arêtes

Ex: sur le graphe initial, S=[| 1; 12 |] et A = {{1; 2}, {2; 3}, {3; 4}, ...}

> [!CAUTION]
> **Rmq**<br>
> A contient des parties à 2 élém et nn des paires car on veut une symétrie. Or {x; y} = {y; x} mais (x, y) != (y, x)

- en anglais, "sommets" = "vertices", "arêtes" = "edges". On note donc parfois (V, E) un graphe
- cette déf interdit:
  - les arêtes d'un sommet vers lui-même
  - plrs arêtes entre 2 même sommets<br>on peut changer la déf pour inclure cela au besoin
- Visuellement, sommet = rond, arête = trait

Notation: dans G=(S,A) un graphe, pour x€S, y€S, on note x-y ou xy si {x; y} € A


Preuve: pour créer une arête, on doit choisir x et y:
- n choix pour                   ) 
- n-1 choix pour y car y != x    ) n*(n-1)

On a compté chq arête 2 fois: {x,y} et {y,x}

Donc n*(n-1)/2

Lemme: un ch de lg min de x à y est élémentaire

Preuve: par contrap. Si (s_0 = x), ..., (s_p = y) est un ch de x à y non-elem, alors il existei, j tq s_i = s_j

Mais alors s_0, ..., s_i, s_j+1, ..., s_p est un ch plus court, donc le ch n'atait pas minimal.

Preuve: si y est acc depuis x, prenons un plus court ch qui est donc elem

Dc (1) => (3)

Or, (3) => (2) et (2) => (1) par def. Dc (1) <=> (2) <=> (3)

