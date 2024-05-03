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


**Complexités temporelles**

- Tester si uv€A : $\Theta$(1)
- Parcourir tous les voisins de s€S : $\Theta$(|S|)
- ajout/retrait uv: $\Theta$(1)
- --------- sommet: $\Theta$(|S|^2) (Il faut tout recréer car les tab ne sont pas redimensionables)

**Complexité spatiale**: la matrice est de taille $\Theta$(|S|^2)


> [!CAUTION]
> **Rmq**<br>
> si le graphe est "creux", càd s'il a peu d'arêtes, on utilise bcp d'espace pour stocker la non-existence d'arêtes: on peut faire mieux dans ce cas

### 2. Par listes d'adjacence


> [!TIP]
> **Déf**<br>
> Soit s€S. La liste d'adjacence de s est la liste de ses voisins.

La repr par listes d'ajacence de G est la donnée du tableau T tel que T[s] est la liste d'adjacence de s, pour tt s€S

<img src="grapherdm.png">

Plusieurs façons d'implémenter les listes d'adja existent:
- une list chainée / un tab dyn
- réserver pour chq liste un espace $\Theta$(|S|) n'en utiliser que les deg(s) 1ieres cases

C'est comme les tab dyn, sauf qu'on reserve tout de suite la taille max

+: + simple
-: gaspillage d'espace

réserver pour les chq liste $\Theta$(S), et dans la deg(s) + 1ieme case mettre une sentinelle de fin


> [!CAUTION]
> **Rmq**<br>
> la notion de sentinelle de fin est celle du '\0' de char*

- On peut ou nn garantir le tri de listes d'adja

Complexité temporelles (pour des listes d'adja chainées non-triées sans doublons)
- présence de uv€A: $\Theta$(deg(u))
  - on parcourt tt la liste de u
- parcourt des voisins de s€S: $\Theta$(deg(s))
  - idem
- ajout/retrait de uv: $\Theta$(deg(u))
  - On parcourt les voisin de u pour voir si y est déjà
  - /!\ Si nn orienté il faut ensuite enlever vu
- ajout/retrait d'un sommet: $\Theta$(|S|)
  - Il faut étendre/réduire T
  - /!\ pour l'ajout, ne pas oublier d'ajouter les nouvelles arêtes
  - /!\/!\ Pour le reatrait il faut retirer le sommet de tt les listes d'adja, soit au total $\Theta$(|S| + |A|)

> [!CAUTION]
> **Rmq**<br>
> Bonne repr qd il y a peu d'arêtes, car alors deg(s) petit et |S| + |A| << |S|^2

Complexité spatiale: $\Theta$(|S| + |A|)
car:
- 1 case par sommet
- 1 elem de liste par arête/arc

### 3. Graphes implicites

Idée: plutôt que de donner soit A on done un our plsr sommets de départ...



> [!NOTE]
> **Exemple**<br>
> Graphe des échecs
> - S= ens des états du plateau pouvant exister
> - A: 1 arête = 1 coup
>
> Ce graphe a environ 10^40 - 10^50
>
> On ne peut le calculer

Par contre, on peut facilement donner l'état initial et les règles du jeu.

---

On veut mq |A| >= (n+1)-1 donc que |A'| >= n-1

Mq G' le graphe induit par S' est connexe. Soient (x,y) 2 sommets de S' (donc x!=u et y!=x)

Par connexité, il existe un ch élem de x à y dans G. Ce chemin ne passe par u puisque x, ..., v, u, v, ..., y n'est pas elem

Donc ce che est un chemin de G'

Donc G' est connexe à n sommets donc |A'| >= n-1 par HR ce qui conclut.



# IV - Parcours de graphe

## 1. Parcours générique

On s'inspire du parcours des arbres, sauf que l'on retient les sommets déjà visités pour ne pas rester bloqués dans un cycle. Çàd on se déplace sur le graphe. La première fois que l'on rencontre chq sommet, on y effectue un "traitement" (qui dépend du pb modélisé)

<img src="olol.png">

*Ya un sac aussi mais flemme de le faire, c'est juste il contient les noeuds*

Ordre d'entrée dans le sac | Ordre de sortie dans le sac/traitement
--|--
3 | 3
4, 6, 7 | 6
7 | 4
1, 5, 8, 7 | 1
0, 2 | 1
-- | 7 -> déjà traité
-- | 5
2, 8 | 8
-- | 2
-- | 7 -> déjà traité
-- | 0


C'est à dire que:
- on a une structure de "Sac" où l'on stocke les prochains à visiter. Il peut contenir les doublons
- Initialement, le sac contient un sommet s_0 choisi
- Tant que le sac est non-vide, on en sort un sommet, on le traite et on ajoute au sac ses voisins non-encore traités

Pseudo-code: sur la feuille


> [!CAUTION]
> **Rmq**<br>
> /!\ Ici on marque un sommet comme déjà vu à **sa sortie** du sac, càd lors de son traitement traitement. Parfois, on marque plutôt à l'entrée: on parle de marquage anticipé

On parle parfois de sommets Blanc, Gris ou Noirs, cela est svt défini ainsi:
- Blanc = jamais entré dans le sac
- Gris = entré, non-encore sorti
- Noir = déjà sorti/traité


> [!IMPORTANT]
> **Propiété**<br>
> le parcours traite exactement les sommets accessibles depuis s_0
>
> Preuve:
> 1. "Tout sommet entré dans le Sac est accessible depuis s_0" est un invariant de la boucle car:
>   - Intialement le sac contient uniquement s_0
>   - à chq iter, les éléms ajoutés sont des y voisin de x (lequel était dans le sac). Donc il y a un chemin s0 --------> x -> y<br><br>
> Donc tt sommet traité est accessible
>
> 2. Supp par l'abs x€G accessible depuis s_0 mais non-traité, et prenons le minimal pour d(s_0, x)
> <img src="bababa.jpg">
> Soit s_0, s_1, ..., s_l (=x) un plus court ch de s_0 à x
> <br><br>
> Par min de x, s_{l-1} a été traité. Mais son traitement aurait dû insérer x son voisin, et x aurait alors fini par sortir et ê traité: abs
>
> 1\) et 2) concluent la preuve


> [!IMPORTANT]
> **Corollaire**<br>
> Un parcours permet de calculer les sommets accessibles depuis s_0. Donc de tester la connexité d'un graphe nn-orienté

> [!IMPORTANT]
> **Corollaire**<br>
> Si l'on peut retirer et ajouter des sommets au sac en tps cst, et sans prendre en compte le temps de traitement d'un sommet, pour un graphe repr. par la listes d'adja, on a la complexité temporelle:<br>
> T(G) = O(|S| + |A|)
>
> ### Preuve:
> 
> Chq sommet est traité au plus 1 fois, et inséré au plus autant de fois qu'il a de voisins. Le traitement d'un sommet se fait en temps deg(s) + 1
>
> Donc T(G) <= (Somme(s€S, deg(s)+1)) = O(|A| + |S|)


---
8 avril


> [!TIP]
> **Déf**<br>
> Soit G=(S,A) un graph et x€S. Lors d'un parcours de G, on note (s'il existe) pred(x) le sommet y dont la visite a inséré dans le sac la 1iere copie de x qui est sorti du sac.

## 2. BFS

Comme dans les arbres, si le Sac est une file, on explore les sommets par distance croissante au sommet initial $s_0$

Exemple:

<img src="./graphddddd.png">

> [!TIP]
> **Déf**<br> On appelle arbre de parcours en largeur l'arbre obtenu en ne gardant que les sommets accessibles depius $s_0$ le sommet initial et les (pred(x), x) comme arcs


> [!IMPORTANT]
> **Propriété**<br>
> C'est bien un arbre
>
> **Preuve:** montrons que, sans son orientation, c'est un arbre<br>
> On sait que:
> - chq arête est un (pred(x), x) <- Autant d'arêtes que de pred
> - chq sommet a un unique prédecesseur <- Autant de pred que de sommets, racine exclue
>
> Donc il y a n-1 arêtes
>
> Pour la connexité, on mq: << Pour tt sommet x traité, $x, pred(x), pred^2(x), ...$ est un chemin fini de x à $s_0$ le sommet initial >> est un invariant (Admis)
>
> Pour tous sommets x, y, on a alors un chemin x, ..., $s_0$, ..., y

> [!IMPORTANT]
> **Propriété**<br>
> Pour un BFS, on peut utiliser un marquage anticipé et obtenir le même ordre de parcours
>
> **Preuve:**
>
> L'ordre de parcours est l'ordre de sortie de la File. Or, la File est FIFO, donc l'ordre de parcours est l'ordre d'entrée: des doublons ajoutés + tard ne chg rien, on peut ne pas les ajouter


> [!IMPORTANT]
> **Théorème**<br>
> - L'arbre d'un BFS est un arbre de plus courts chemin de $s_0$ le sommet initial vers les sommets accessibles.
> - Le BFS parcourt par distance croissante à $s_0$
>
> **Preuve:** adapter les arbres


Code OCaml: cf annexe

## 3. DFS (récursif)

**Idée:**

On "s'enfonce" le + possible dans le graphe. Lorsque l'on est bloqués; on revient sur nos pas jusqu'à trouver un nouvel embranchement.

C'est un parcours naturellement récursif

<img src="./graphparcours.png">

Pseudo-code: cf annexe

> [!IMPORTANT]
> **Théorème**<br>
> L'arbre de parcours d'un DFS (ie l'arbre des (pred(x), x)) est un arbre T=(S,A) enraciné en $s_0$ le sommet initial qui vérifie: 
> 
> Si xy est une arête de G qui n'est pas dans T, alors x est ancêtre de y dans T ou y de x
>
> **Preuve:** Admis/MP

Ex:

<img src="./graphparcours2.png">

2-3 ne vérifie pas la ppté pour un BFS mais la vérifie pour un DFS

> [!CAUTION]
> **Rmq**<br>
> Ce thm dit que << si l'on a pas emprunté xy, c'est que lorsque l'on a visité on s'est enfoncé dans un autre chemin qui a mené à y (ou l'inverse)>>


## 4. Parcours Pile

Si l'on prend le parcours générique où le Sac est une Pile, on obtient:
- un DFS si l'on marque en sortie du Sac/Pile
- /!\ **PAS** un DFS si marquage anticipé /!\

contre-ex pour le 2nd point:

<img src="./contreex.png">

est obtenu avec un parcours Pile et marquage anticipé. L'arête 2 - 3 ne vérifie pas le thm

> [!CAUTION]
> **Rmq**<br>
> Ce parcours n'est pas un BFS non-plus
>
> <img src="./contreex2.png">

## 5. Parcours du graphe en entier

Rappel: un parcours ne visite que les sommets accessibles depuis $s_0$

Si on veut tous les visiter, on peut procéder par parcours successif:

```
Pour chq sommet: 
  s'il n'a pas été marqué lors d'un parcours précédent:
    Lancer un parcours depuis ce sommet.
```

Complexité: ss les même hyp que le parcours général, on a:

C(G) = $\Theta$(|S| + |A|) si les listes d'adj = $\Theta$($|S|^2$) si matrices d'adj

On peut utiliser ce principe pour calculer les composantes connexes : tous les sommets visités lors d'un même parcours forment exactement une composante connexe, puisque c'est l'ensemble des sommets accessibles depuis le sommet initial de ce parcours.

Pseudo-code: on veut remplir un tableau CC qui stockent le numéros de la CC de chaque sommet.

```
CC <- tableau à n cases, init à -1
num <- 0

Pour chq sommet s€S:
  Si CC[s] = -1:
    Lancer un parcours depuis s
    // le traitement d'un sommet u lors de ce parcours est CC[u] <- num
    num <- num + 1
  
  Renvoyer CC
```

> [!CAUTION]
> **Rmq**<br>
> Un tel algorithme qui lance plusieurs parcours pour visiter tous les sommets est appelé un **parcours complet du graphe**.

## 6. Tri topologique

On considère ici des graphes orientés acycliques. On les interprètes comme des dépendances, et on veut traiter les tâches indiquées dans l'ordre:

<img src="./graph_rdm2.png">

Autre ex:
- construction d'un meuble/avion
- boot d'un ordinateur
- éditions de liens lors de la compilation: si le fichier A dépend de B, il faut gérer B avant A


> [!CAUTION]
> **Rmq**<br>
> - On se limite à des graphes acycliques car un cycle donne des tâches qui dépendent d'elle-même (cf oeuf-poule)
> - On abrège graphe orienté acycliques en DAG (Directed Acyclic Graph)


> [!TIP]
> **Déf**<br>
> Soit G=(S, A) un DAG
>
> On dit que l'ordre large ≼ sur S est un ordrre topologique ss'il est total et que l'ordre strict associé ≺ vérifie !
>
> pour tt (u,v)€A, u ≺ v



> [!CAUTION]
> **Rmq**<br>
> - Un chemin orienté est une suite st croissante pour tout ordre topologique
> - Si l'on a calculé un ordre topo sur un graphe, il suffit de traiter les tâches par ordre topologique croissant pour avoir un ordre de traitement "qui fonctionne"
> - Il n'y a pas unicité d'un ordre topologique 
>
> <img src="./graph_rdm22.png">

Pour calculer un ordre topo, on va utiliser un **DFS récursif**

On dit que l'on:
- ouvre un sommet lors de ce parcours au début de son 1er appel
- ferme un sommet à la fin de son appel, càd après la fin de l'exploration rec de ses voisins.

On explicite souvent une notion de "temps/moment/etc": initialement le temps est t=0, et est incr de 1 à chq ouv/fermeture.

<img src="./graphe12avrl.png">

On fait un DFS rec complet dans l'ordre a, b, ..., f et on note les tps


> [!CAUTION]
> **Rmq**<br>
> - un sommet est ouvert lors de son 1er appel, càd lorsqu'il est traité pour la 1ière fois, càd lorsqu'il devient Noir.
>
> - Si (u,v)€A, on n'a u -> v ni forcément ouverture(u) < ouverture(v)<br>
> ni forcément ouverture(u) > ouverture(v) (cf ex prec)
> - On n'a pas non plus (u,v)€A qui impliquerait fermeture(u) <fermeture(v) (idem)


> [!IMPORTANT]
> **Théorème**<br>
> Soit G=(S, A) un DAG.
>
> On considère un DFS rec complet de G et on note fermeture(s) la date de fermeture(s). Or:<br>
> pour tous u et v € S<br>
> (u,v)€A => fermeture(u) > fermeture(v)
>
> Preuve:
>
> soit xy€A<br>
> Distinguons 2 cas:
> - Si le DFS rec complet ouvre y avant x<br>Montrons que x n'est pas visité à cause de l'appel récursif de y<br>En effet, si c'était le cas, on aurait y -> voisin de y -> ... -> x comme suite d'appels
>
> Donc x serait accessible depuis y
>
> DOnc il y aurait un cycle car y -> ... -> x -> y est un ch non-vide de y à y. Abs. Donc l'appel sur y n'entraine pas d'appel sur x, donc l'appel à y se ferme avant que x ne soit ouvert:
>
> ouverture(y) < fermeture(y) < ouverture(x)
>
> Comme fermeture(x) > ouverture(x), on a fermeture(x) > fermeture(y)
>
> Sinon: lors de l'appel de x, y n'est pas ouvert (donc pas Noir/marqué)
>
> Donc l'appel de x appelle pour la 1iere fois y et l'ouvre. Donc l'appel de x attend la fin de l'appel de y pour terminer, càd:
>
> ouverture(x) < ouveture(y) < fermeture(y) < fermeture(x)


Corollaire:

On obtient un tri topologique en posant u ≺ v lorsque fermeture(u) > fermeture(v)

Preuve: thm prec


> [!CAUTION]
> **Rmq**<br>
> - Pour calculer un tri topo, les dates d'ouvertures sont inutiles et on peut ne pas les calculer.
> - Complexité: celle d'un parcours donc:
>   - O(|S| + |A|) si liste adja
>   - O(|S|^2) si mat adja


> [!IMPORTANT]
> **Propiété**<br>
> Un graphe orienté qcq admet un ordre topo SSI c'est un DAG

Preuve:

<=] cf coro prec

=>] S'il y a un cycle, il n'y a pas d'ordre top car un cycle s0, ..., sl-1, s0 implique s0 ≺ s1 ≺ ... ≺ sl-1 ≺ s0

Donc s0 ≺ s0: abs

Ex de tri topo sur DAG non-connexe

<img src="./qjdnqzdzjdd.png">

## 7. Détection de cycles orientés

En lançant un DFS récursif complet, on peut détecter un cycle

En effet si un graphe orienté G=(S,A) contient un cycle, alors: on a s0, s1, ..., sl-1, s0 un cycle

Quitte à les renommer, supposons que s0 soit le 1er sommet ouvert de ce cycle. Alors comme il y a un chemin de s0 à sl-1, sl-1 sera ouvert avant que s0 ne se ferme:

ouverture(s0) < ... (= en chemin d'appels rec de s0 à sl-1) < ouverture(sl-1) < fermeture(sl-0) < fermeture(s0)

Donc lors de l'appel sl-1, son voisin s0 est ouvert non-encore fermé

Montrons mtn que réciproquement, si lors d'un DFS rec complet, quand on ouvre en sommet il a un voisin ouvert non-encore fermé, alors il y a un cycle.

Soit v un sommet qui lors de son ouverture lors d'un tel parcours, a un voisin ouvert non-encore fermé:

Puisque u n'est pas encore fermé, sa suite d'appels réc n'est pas terminée

Autrement dit, v est un appel qui provient rec de u

Donc il existe un chemin u -> ... -> v -> u non-vide de u à u, donc un cycle


> [!IMPORTANT]
> **Théorème**<br>
> Un graphe orienté G=(S,A) est acyclique SSI lors d'un DFS rec complet, qd un sommet est ouvert il n'a aucun voisin ouvert nn encore fermé

Preuve: au dessus


> [!CAUTION]
> **Rmq**<br>
> - ici, mémoriser ouverture et fermeture est indispensable
> - complexité celle d'un parcours


> [!IMPORTANT]
> **Théorème**<br>
> Si G est non-orienté, on peut adapter la méthode préc en :
>
> lors d'un DFS complet rec, si lors de l'ouverture d'un sommet u il a un voisin v **qui n'est pas son prédecesseur dans l'ordre induit** et qui est ouvert non-encore fermé, alors le graphe admet un cycle. La réciproque est également vraie.


"Preuve": on obtient en chemin sans enchainement x-y-x (grâce à v != pred(u)) de v à v donc il existe un cycle.