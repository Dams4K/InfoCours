# Structures de données (S1)

## I - Types abstrait

### 1. Defs

> [!TIP]
> **Déf**<br>
> Une structure de données est une façon d'organiser des données pour les manipuler

> [!TIP]
> **Déf**<br>
> Un type abstrait (ou str de données abstr) est en considération abstraite des données. On se donne une notration pour les décrire ainsi que l'ens des op que l'on peut faire


> [!CAUTION]
> **Rmq**<br>
> Il faudra bien distinguer le type abstrait de son implem. concrète


> [!NOTE]
> **Exemple**<br>
> - Tableau dynamique: on peut déf en t.a. (type abstrait) qui "parle" de case, d'ajout à la fin et de suppr à la fin, mais il ne dit pas cmt les coder
> - Listes OCaml: ont sait comment les maniuler, on n'a pas vu cmt les représenter en mémoire.
> - Nombres à virgule: le t.a. décrirait ce que l'on veut faire avec (+, -, *, /, etc), mais pas cmt les coder


> [!CAUTION]
> **Rmq**<br>
> Le frontière entre abstr et implem dépend du pov. Pour nous, les pointers sont un brique de base... pas pour la personne qui les a créés et réalisés avec un fer à souder

### 2. Utilité

La conception d'un algo complexe peut se faire par raffinements successifs: on se donne d'abord uniquement les t.a. de str. données utiles, on résout le prblm avec, puis on se demande cmt implem ces t.a., etc.


> [!CAUTION]
> **Rmq**<br>
> Le compilateur fait les derniers raffinements: il "implémente le langage"
>
> L'autre utilité est de ne pas imposer une implémentation particulière et de permettre de changer


> [!NOTE]
> **Exemple**<br>
> on résout un pb avec un t.a. tab dynamique. Ça marche! Plus tard, on peut changer l'implem de ces tab dyna: tq l'implem respecte le t.a., la solution marche tjrs

### 3 Signature


> [!TIP]
> **Déf**<br>
> La signature d'un type abstrait est une descri de la syntaxe du type. Elle donne:
> - L'identifiant
> - Les autres types dont il a besoin
> - Les identifians de constantes du type
> - La signature des opérations (fonctions) du type, ie poour chq op du type on donne son nom, le type de ses entrées, le type de sa sortie


> [!NOTE]
> **Exemple**<br>
> type: Booléen<br>
> utilise: /<br>
> cst:
> - vrai: Booléen
> - faux: Booléen
>
> Opéra:
> - Non: bool -> bool 
> - Ou: bool -> bool -> bool
> - Et: bool -> bool -> bool
> - Xor: bool -> bool -> bool
> - Xand: bool -> bool -> bool


> [!NOTE]
> **Exemple**<br>
> type: Tab Dyna<br>
> utilise: Entier, Élément
> cst: /
> Opéra:
> - Créer: Entier x Élément -> Tab.Dyna
> - Accès: TabDyna x Indice -> Élément
> - Modif: TabDyna x Indice x Élément -> /
> - Ajoute: TabDyna x Élément -> /
> - Retire: TabDyn -> Élément
> - Longueur: TabDyn -> Entier


> [!IMPORTANT]
> **Propriété/Remarque**<br>
> La signature ne suffit pas à définir un t.a. : il faut aussi donner du sens. On parle de sémantique. Pour ce faire, on peut indiquer des propriétés respectées par les op. On parle d'axiomes du type d'abstrait.


> [!NOTE]
> **Exemple**<br>
> Sur les tab dyna:
> Pr tt n Entier, pr tt x Élément, Longueur(Créer(m, x)) = n
>
> Pr tt t TabDyn, pr tt x Élément, pr tt i € [| 0; Longueur(t)| ],<br>
> Accès(Modif(t, i, x), i) = x


> [!CAUTION]
> **Rmq**<br>
> donner la cplxité des op revient parfois à imposer une implem spécifique ou à interdire certaines. C'est pourquoi il est parfois recommandé de ne pas les mettre


> [!TIP]
> **Déf**<br>
> Parmi les op d'un t.a., on parle de:
> - constructeur: pour les op qui crée ou initialise une str de donnée
> - accesseur: pour les op qui récupèrent une valeur liée à la str de donnée
> - transformateur: pour les op qui modifient m'état de ma str donnéees


> [!NOTE]
> **Exemple**<br>
> Pour TabDyn
> - Créer : constructeur
> - Accès : accesseur
> - Modifier: transformer
> - Ajoute: transformateur
> - Retire: accesseur **et** transformateur
> - Longueur: accesseur

## II - Interfaces

cf TD

## III - Structures de données séq

### 1. Tableaux

Rappel:
- on a déjà vu un certain nb de types prédéfinis, comme les `bool`, `int`, `double`, (flottants)
- on a vu également qu'un type peut-être déf à partir d'autres ("utilise" du t.a.) -> ex: 'a list en OCaml


> [!IMPORTANT]
> **Propriété (Rappel)**<br>
> Un tableau est repr en mémoire par des cases contigües contenant les repr des elem du tableau. Les cases ont donc même taille (la taille du type des elem). Il est affaibli en pointeur quand passé en argument/renvoyé (on ne donne pas ses valeurs mais son addresse)


> [!CAUTION]
> **Rmq**<br>
> On impose généralement que l'accès et la modif d'une case se fasse en temps cst

Schéma:
[ Valeur | Valeur1 | ... | Valeur(T-1) ]

### 2. Liste linéaire


> [!TIP]
> **Déf**<br>
> Une liste linéaire est une suite finie, éventuellement vide, d'éléments repérés par leur rang : l = <l<sub>0</sub>, l<sub>1</sub>, ..., l<sub>n-1</sub>>


> [!IMPORTANT]
> **Propriété**<br>
> Si E est l'ens des elem possible, l'ens **L** des listes linéaire sur E peut-être rec def par : **L** = O/ + Ex**L** (O/ l'ens vide)


> [!TIP]
> **Déf/Propriété**<br>
> La signature de ce t.a. est:
> - type: Liste Linéaire
> - utilise: Entier
> - cst: <>: L.L.
> - op:
>   - longueur: L.L. -> Entier
>   - acces_ieme: L.L. x Entier -> Élément
>   - inser_ieme: L.L. x Entier x Elem -> L.L.
>   - suppr_ieme: L.L. x Entier -> L.L.


> [!CAUTION]
> **Rmq**<br>
> ici, les transformateurs renvoient une nouvelle liste linéaire au lieu de modifier celle qui leur est passé en argument: on parle de str. données fonctionnelle.
> En particulier, les transfo sont plutôt des constructeurs
>
> Quand a contraio les transfo modifient la str. données passée en arg, on parle de str. don. impérative


> [!CAUTION]
> **Rmq**<br>
> Une version impérative de L.L.
> donnerait:
> idem
>  inser-ieme: ll entier elme -> rien
> sjmmr kk entier -> rien

## IV - Piles

Un cas particulier des listes linéaires est ce que l'on nomme des Piles: il s'agit de listes linéaires où l'insertion, la suppression et l'accès sont limités au 1er élément

On les représente généralement verticalement (pas de schéma t'es pas con)

(pas de schéma d'évolution d'une pile t'es pas con nn plus)


> [!IMPORTANT]
> **Propiété**<br>
> Une Pile a la propriété "Last In, First Out" abrégé LIFO: le premier élément à sortir est le dernier à être entré
>
> Plus formellement, si on note: e0, e1,... les états successifs de la pile<br>
> - in(x) le numéro de l'état obtenu après l'insertion de x
> - out(x) ----------------- la suppression de x
>
> Alors: pour tout x, y : in(x) < in(y) => out(y) < out(x)


> [!NOTE]
> **Exemple** de situations à ppté LIFO<br>
> - blocs syntaxe (portée, durée de vie auto): le premier bloc à ê fermé est le dernier à ê ouvert
> - exo que vous pouvez croiser: fonctionnement de la notion polonaise inversé
> - les appels de fonction:
>   - La fonction en cours est la dernière à avoir été appelé
>   - qd on la termine, on revient à la fonction suivant dans la pile -> On parle de la pile d'appels des fonctions, aka la pile mémoire
>   - vérifier si une expression est bien parenthésée

#### a. Implem par tableau

2 grandes façons:
- Faire un tableau de capacité max N, mémoriser le nb de cases utilisées, insére/suppr à la fin
- Idem, mais avec des tab dyna : permet de s'affranchir de la capacité max.


> [!CAUTION]
> **Rmq**<br>
> Par rapport aux listes linéaire, ici l'élément de "1iere position" est à droite: la pile est rangée de droite à gauche dans le tableau.

#### b. Par listes chainées

RAS, ĉ listes linéaires: cf TP

## V - Files

On peut restreindre les listes linéaires à insérer en 1iere position, accéder et supprimer en dernière position: on parle de Files


> [!IMPORTANT]
> **Propiété**<br>
> Une file a la ppté "First In First Out" : les éléments sortent de la file dans l'ordre où ils y entrent


> [!NOTE]
> **Exemple** de situations à ppté FIFO<br>
> - Gestion de file d'attente (serveur web, les de commandes dans un terminal)

### a. Implem par tableau circulaire

Une première idée est de faire "ĉ les piles"

Prblm: le contenu du tableau se "décalre vers la droite". On finit par arriver à ce type de situation:

[ ? | ... | ? | x | ... | xn ]

Ici pour insérer on devrait agrandir ke tabkeay alors qu'il y a bcp de cases libres

Trois solutions:
- agrandir qd mm à la "tab dyna" ça marche mais gaspille de la place
- décaler les cases occupées de la droite vers la gauche: si on ne le fait pas trop souvent, la cplexité amorte est bonne (eg ne le faire que lorsqu'on agrandit le tableau)
- dire que le tableau est en fait **circulaire**: on fait ĉ si la 1iere case suivait la derniere


> [!NOTE]
> **Exemple**<br>
> On stocke début de l'indice de la première case, et len le nombre d'éléments

On utilise donc (cf TP)
- un tableau **contenu**, de longueur C
- un indice **sortie** qui stocke l'indice de la sortie de la file
- un nombre d'éléments **len**

Les éléments de la file sont stockés (dans l'ordre de sortie) de `sortie` à `sortie+len-1` inclus (/!\ Circularité):

[x2, x3, ..., x0, x1]<br>
. . . . . . . . . . ^ sortie

La circularité est prise en compte en calculant les indices modulo C


> [!NOTE]
> **Exemple**<br>
> 
> File vide: [ | | | ... | | ]<br>
> . . . . . . . . . ^ sortie
> 
> La position de la sortie importe peu
> 
> Enfile:
> 
> [x2, x3, ..., x0, x1]<br>
> . . . . . . . . . . ^ sortie
>
> (enfile x4) -> len' = len + 1
>
> [x2, x3, x4, ..., x0, x1]<br>
> . . . . . . . . . . . . . ^ sortie
>
> ie on écrit en `(sortie + len) % C` et on incrémente len
>
> Défile:
> 
> [x2, x3, x4, ..., x1]<br>
> . . . . . . . . . . . . . ^ `sortie' = sortie + 1 % C`
>
> ie on décrément len et incrémente sortie (mod C)

### b. Implem par listes simpl chainéees

Idée: on stocke les valeurs dans une liste simpl chainée. La sortie de la file est la tête de la liste et l'entrée de la file est le fond de la liste

One ne mémorise que 2 ptrs
- 1 vers la tête
- 1 vers le fond

ptr sortie -> [ x0 |--> [ x1 |--> [ x3|X] -> ptr entrée


> [!NOTE]
> **Exemple**<br>
> - File vide: les deux **ptr** pointent sur rien (NULL)
> - Tester si la file est vide: on teste si les **ptr** sont NULL ou non
> - Défiler : on fait pointer **ptr** sortie vers l'élem suivant
> - Enfiler : on crée un nouveau maillon on fait pointer le fond de la liste dessus et on maj ptr entrée

## VI - Variantes des Files

### 1. File de priorité

-> cf S2

Idée: files, mais où les elems sortent par **priorité** et non FIFO

### 2. Files à doubles entrées

Idée: un file, mais où on peut enfiler/défiler des 2 côtés:

-> . . . . . . . . . . -><br>
 | x0 | x1 | x2 |
<br><- . . . . . . . . . . <-

Implem:
- par tableaux circulaires
- par listes doublement chainées

[X| x0 | <-> | x1 | <-> | x2 |X]

ie chq maillon mémorise le maillon prec et suivant

NB: en python, les files à double entrée sont des deque (Double Ended Queue)