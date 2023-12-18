# Organisation De La Mémoire

## I - Schéma physique d'un ordinateur

<img src="./schéma_processeur.png">

**Processeur:** **Central Processing Unit**, c'est lui qui fait les calculs. Il a plusieurs "coeurs" (plrs mini-cpu), qui peuvent calculer en même temps. Sa vitesse de calcul est de 2.10⁹ Hz (par coeur)

Cache (Hors Programme): petite mémoire proche du processeur, Très rapide d'accès, on y pré-charge des morceaux de la RAM pour y accéder plus vite.<br>
Volatile 🐦🐦🐦🐦🐦🐦🐦🐦

**Mémoire:** "environ 8Go" modérement rapide d'accès.<br>
Volatile: s'efface à l'extinction.<br>
C'est la que les données d'exécution de nos programmes sont stockées

**Mémoire morte:** "environ 50Go" lente d'accès<br>
Pérsistante: n'est pas modifiée par l'extinction

**Périphériques:** Entrées/Sorties branchées à la machine

Un programme n'interagit pas directement avec les composants physiques. Il y a un super-programme dont le travail est d'ordonner ces interactions: c'est le système d'exploitation (Operating System)

Ex d'OS:
- GNU/Linux: dominants sur les serveurs (de très loin) et chez les informaticiens
- Android (dérivé de Linux): dominant sur les smartphones
- Windows: dominant sur les machines personnelles
- (macOS: dérivé de Unix, un ancêtre de Linux)

> [!CAUTION]
> **Rmq**<br>
> Linux est une très grande famille d'OS, qui peuvent être très différents

Dans ce cours on étudie comment la RAM est "vue" par un programme: on parle de mémoire virtuelle

## II - Orgranisation de la VRAM

### 1. Portée, Durée de vie

> [!TIP]
> **Rappel**<br>
> La portée d'un identifiant est l'ensemble des endroits où on peut l'appeler. Elle peut-être :
> - globale (jusqu'à la fin du fichier, à partir de la déclaration de l'id)
> - locale (à partir de la déclaration jusqu'à un certain point)
> 
> Il peut y avoir masquage: dans la portée d'un identifiant `id`, on crée un autre identifiant identique `id`. La portée de ce nouvel id est une zone où on ne peut pas accédder à l'ancien ("le plus récent l'emporte").

> [!NOTE]
> **Exemple**<br>
> ```ocaml
> let y = (let x = 3 in let x = x+2 in x/2)
> ```
>
> `y`: Déclaration globale: portée: de la fin de sa déclaration à la fin du fichier
> `x`: local + masquage toujours en local

Certains id ont besoin que leur portée **inclut** leur déclaration: ils sont récursifs

> [!NOTE]
> **Exemple**<br>
> ```ocaml
> let rec f = fun n -> if n = 0 then 0 else f n+1
>```
>
> `y`: f id rec

> [!TIP]
> **Def**<br>
> La durée de vie d'un objet mémoire est l'ensemble des zones de code où cet objet "existe", ie a une valeur connue

> [!NOTE]
> **Exemple** en C<br>
> `|` portées de n
> `-` durée de vie du contenu de n (vide)
> ```C
> int n;
> |int s = n+2;
> |
> // NON ! n n'a pas de valeur, Undefined Behavior, Ici Portée, mais pas Vie
> ```
>
> ```C
> |- int n = 2;
> |- {
> .-   int n = 0;
> .-   int s = n*2;
> |- }
> |- int x = n+1;
> ```

> [!IMPORTANT]
> **Propiété**<br>
> Il y a trois sortes de durées de vie en C:
> - statique: l'objet est **toujours** défini en mémoire, il est **toujours** vivant
> C'est le cas des variables globales coonues à la compilation
> - automatique: l'objet n'existe en mémoire que durant un bloc (généralement sa portée). Il est automatiquement supprimée à la fin. C'est le cas de la plupart des variables locales.
> - allouée: on contrôlera à la main >> le début et la fin de la durée de vie (en C, malloc/free)

> [!TIP]
> **Déf**<br>
> Certains langages (dont OCaml mais pas C) essayent de détecter quand est-ce qu'un objet alloué ne pourra plus servir afin de le supprimer. On parle de "ramasse-miettes"

> [!CAUTION]
> **Rmq**<br>
> C'est pratique (pas à gérer la mémoire à la main, moins d'erreurs) mais cela ralenti le programme

> [!CAUTION]
> **Rmq**<br>
> La plupart des OS libèrent de force la mémoire d'un prgm à la fin de celui-ci

> [!IMPORTANT]
> **Propriété**<br>
> Les objets à durée de vie automatique en C ont une propriété intéressante: si des blocs sont imbriqués le premier bloc à "naite" sera le dernier à "mourir"

> [!NOTE]
> **Exemple**<br>
> ```C
> | int f(int n) {
> |     int s = 0;
> |     int x = 3;
> |     - for (int i = x; iq10; i++) {
> |     -     * for (int j = x-i; j < x+2; j++) {
> |     -     *     s = s+j;   
> |     -     * }  
> |     - }
> | }
> ```
>
> `|` bloc et durée de vie du cours de la fonction<br>
> `-` bloc et durée de vie de la premiere boucle for<br>
> `*` bloc et durée de la vie de la seconde boucle for<br>
>
> On a l'ordre de naissance / mort suivant:
> naissance(s, x)<br>
> |<br>
> naissance(i)<br>
> |<br>
> naissance(j)<br>
> |<br>
> mort(j)<br>
> |<br>
> mort(i)<br>
> |<br>
> mort(s, x)<br>
>
> On parle de "LIFO"

### 2. Bloc d'activation

> [!TIP]
> **Déf**<br>
> Un bloc d'activation est un ensemble d'objets à durée de vie automatique qui naissent en même temps et meurent en même temps

> [!NOTE]
> **Exemple**<br>
> Dans l'exemple précédent, les variables de chaque bloc forment un bloc d'activation

> [!IMPORTANT]
> **Propriété**<br>
> - Les objets d'un même bloc d'activation seront les uns après les autres en mémoire
> - pour une fonction, le bloc d'activation inclut également:
>   - ses arguments
>   - des "méta-données" pour savoir à qui "répondre et rendre la main" à la fin de la fonction

> [!IMPORTANT]
> **Théorème**<br>
> En C, chaque bloc syntaxique ({...}) correspond à un bloc d'activation

> [!CAUTION]
> **Rmq**<br>
> les compilateurs modernes simplifient souvent et disent que chaque fonction correspond à un bloc d'activation

### 3. Schéma de la VRAM

La mémoire est une sorte de tableau géant, indicé par des adresses mémoires (un pointeur) Sur GNU/Linux, en C, elle est organisée ainsi:

<img src="./encore_un_dessin.svg">

Légende:
- Code: là où les instructions de la version compilée du prgm st stockée
- Données statiques: les variables globales du programme. Le compilateur sait quelle sera leur taille (leur type)
La VRAM a une zone réservée pour ces variables. Elle est découpé en deux données soit non-init (var globales dont on connait la taille mais pas la valeur), et données stat init (var globales dont on connait la taille et la valeur)
- Pile: là où les différents blocs d'activation en cours sont stockés. Quand un bloc est crée on l'ajoute en bas de la pile; qd on quitte un bloc on le supprime (il est en bas de la pile, LIFO)


> [!IMPORTANT]
> **Propiété**<br>
> La taille requise par un bloc d'activation est connue à la compilation. A l'éxecution on peut donc créer un bloc sur la pile qui a **exactement** la taille nécessaire. Il n'y a pas besoin de laisser des trous "au cas où" la pile est remplie contigument (=les un à la suite des autres)


> [!IMPORTANT]
> **Propiété**<br>
> La taille de la pile évolue durant l'exécution

- Tas: la zone où sont allouées les objets à durée de vie allouée. Qd le programme demande d'allouer un objet d'une taille donnée (`malloc` en C), l'OS réserve un bloc de la bonne taille dans le tas et en donne l'adresse au programme. Il ne sera supprimé que lorsque le programme le demande


> [!IMPORTANT]
> **Propiété**<br>
> Le tas ne peut pas être rempli contigument (car la taille des objets allouées peut-être dynamique, càd dépend de l'exécution). Généralement, ce n'est même pas le but d'un allocateur.


> [!NOTE]
> **Exemple**<br>
> x <- Allouer 1 case<br>
> y <- Allouer 3 cases<br>
> z <- Allouer 2 cases<br>
> Désallouer (y)<br>
> t <- Allouer 1 case<br>
>
> Essayer de remplir contugement donnerait:
>
> -------------------> adresses
> ```
> [ X |    Y    | Z ]
> ```
> ```
> [ X ]         [ Z ]
> ```
> ```
>[X |  T  ]    [ Z ]
> ```


> [!IMPORTANT]
> **Propiété**<br>
> La taille totale du Tas évolue durant l'exécution (il s'agrandit "qd" il n'a plus de "trou" assez grand pour une allocation)


> [!CAUTION]
> **Rmq**<br>
> - Si l'agrandissement de la Pile ou du Tas n'est pas possible (car plus de place), on obtient en C une erreur `Stack Overflow`
> - La taille maax de la Pile et du Tas sont définis par l'OS. En 1ière approximation, Pile + Tas ≃ "tout l'espace non-utilisé de la RAM"
> - La Pile mémoire se comporte comme la structure de données Piles; mais le Tas mémoire ne se comporte pas comme la structure données Tas (cf S2). Par contre, le Tas mémoire est parfois géré à l'aide de la structure de données Tas
> - Dans certains cas, il peut y avoir assez de place dans le Tas pour allouer tt les cases d'un objet lui-même

> [!NOTE]
> **Exemple**<br>
> ```
> [ 1 ] *1* [ 1 ] *1* [ 1 ]
> ```
> Ici il y a 2 cases libres, mais on ne peut pas allouer un objet de taille 2 (il n'y a pas 2 cases libres côte à côte pour créer une zone de taille 2)

## III - Retours sur la portée != vie

Aux exemples précédents, ajoutons:

```C
int* p = (int*) malloc (...); // L'objet *p est accessible
free(p);
int x = p[0]; // Ici *p est accessible mais mort...
```

```C
int* f(void) {
    int n = 666;
    return &n;
}
```

Le pointeur renvoyé pointe dans le bloc d'activation de f. Hors, à la fin de f, ce bloc d'activation est supprimé: le pointeur pointe vers un objet mort.

```C
void g(n) {
    malloc(n * sizeof (char));
}
```

On alloue un objet mais on ne le supprime jamais (et on ne peut pas le faire car on ne connais pas sont adresse) : l'objet ne sera jamais tué et est inaccessible

Ccl: Portée != Durée de vie. Il faut **TOUJOURS** libérer la mémoire que l'on a allouée

## IV - Coûts spatiaux

### 1. Tableaux en C

Un tableau est une variable à durée de vie automatique. Sa taille est `nb_de_case * taille_d'1_case`

Ils vont donc sur la pule (ou dans les données statiques s'il sont globaux)
Il y a cependant une subtilitée

Quand on passe un tableau à une fonction, on ne le passe pas par valeur (on ne le recopie pas) Le tableau est "affaibli en pointeur" : on passe à la place un pointeur vers le début du tableau. D'om le fait que les cases se comportent comme passage par référence.

Ainsi, passer un tableau en arg à une fonction ne consomme que la taille d'un pointeur en espace

### 2. Fonctions

Pour fonctionner, une fonction a besoin de:
- (sur le Tas assez d'espace pour ses allocations)
- sur la Pile, assez d'espace pour son/ses blocs d'activation
- sur la Pile, assez d'espace pour ses appels de fonction

En particulier, une fonction récursive consomme `nombre_maximal_d'appel_en_cours * espace(sur la pile)_d'un_appel` (-> cf S2)

Donc: la complexité a un coût spacial:

> [!CAUTION]
> **Rmq**<br>
> Si le seul appel qu'un fonction récursive fait à elle-même est fait à la toute fin de la fonction (derniere opération) on peut optimiser en remplaçant l'appel en cours par l'appel suivant

> [!NOTE]
> **Exemple**<br>
> En Ocaml:
> ```ocaml
> let rec sum x n = fun x n ->
>    f n = 0 then x
>    else sum (x+n) (n-1)
> ```
> Ici, dans le cas récursif, on fait:
> - calculer x+n
> - calculer n-1
> renvoyer sum (x+n) (n-1)

Autrement dit, il ne sert plus a rien de conserver la mémoire de l'appel en cours durant l'appel rec: le compilateur optimise en rempmaçant le bloc d'appel en cours par le bloc suivant. Cette fonction n'a besoin que d'1 bloc d'activation. Cette fonction est compilé comme une boucle:<br>

Pour i de n à 0:<br>
    x <- x + 1

On parle de récusrivité terminale. Le compil OCaml le fait  