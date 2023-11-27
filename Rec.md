# Récursivité

Déf: on dit qu'un problème de A se réduit à un pb B lorsque résoudre B suffit pour résoudre A

> [!NOTE]
> **Exemple**<br>
>
> A: Entrées: (x, y) ∈ (**N\***)<sup>2</sup><br>
> $\hspace{8pt}$ Tâche: calculer pgcd(x, y)
>
> B: Entrées: (x, y) ∈ (**N\***)<sup>2</sup><br>
> $\hspace{8pt}$ Tâche: calculer ppcm(x, y)
>
> En utilisant `ggcd(x, y) * ppcm(x, y) = xy` On peut réduire A à B: `pgcd(x, y) = xy / ppcm(x, y)`

> [!CAUTION]
> \- On note A ≼ B si A se réduit à B<br>
> \- Si A ≼ B, pour résoudre A on a **pas** besoin de connaitre le fonctionnement d'une fonction qui résout B : il suffit d'en avoir une, et de l'utiliser comme une boite noire

L'idée de la récursion est de déduire A à lui-même, càd résoudre des instances de A à l'aide d'autres instances de A.

> [!NOTE]
> **Exemple**<br>1
> `u`<sub>`n`</sub>` = u`<sub>`n-1`</sub>` + 1 si n > 0` $\hspace{25pt}$ `0 sinon`
>
> Alors *"Calculer u<sub>n</sub>"* reviens à *"Calculer u<sub>n-1</sub>"*

> [!CAUTION]
> \- En C une fonction peut s'appeler elle-même<br>
> \- En OCaml il faut le mot-clef `rec`

## Exemples introdutifs

### 1. La factorielle

On déf sur **N**: $\begin{cases} n! = n(n-1)! & \quad \text{si } n > 0 \\ 1 & \quad \text{sinon} \end{cases}$

C'est une déf réc! On réduit "calculer $n!$" à "calculer $(n-1)!$", sauf si $n = 0$ auquel cas $n$ renvoie $1$

### 2. Triangle

Entrée: $n$ un entier<br>
Tâche: Dessiner un triangle de $n$ lignes d'étoiles

Une méthode rec est :
- écrire une ligne de $n$ étoiles
- puis si $n > 1$, recursivement tracer un triangle de $n-1$ lignes en dessous

### 3. Tours de Hanoï

Pour résoundre le problème on réduit le problème de déplacer $n$ disques d'un emplacement à un autre à celui de déplacer $n-1$ disques. Cette réduction n'a pas de sens si $n = 0$: c'est le cas de base qu'il faut gérer à part.

Cela donne le pseudo-code donné en annexe

> [!WARNING]
> Pour que cela fonctionne, on utilise implicitement une hypothèse: nos `n` disques à déplacer sont les plus petits. Anisi, durant les appels récursifs, lorsque l'on est amenés à déplacer des disques sur d'autre, cela sera bel et bien autorisé

> [!NOTE]
> **Contre exemple**<br>
> "*Déplacer le 1<sup>er</sup> disque sur l'emplacement libre, les `n-1` du dessous sur l'emplacement de destination puis le 1<sup>er</sup> disque à nouveau*"
>
> Ne fonctionne pas car des appels récursifs vont devoir placer un disque plus gros sur un disque plus petit

### 4. Exponentiation rapide

#### Probleme:
Entrée: a ∈ **Z**<sup>*</sup>, n ∈ **N**
Tâche: calculer a<sup>n</sup>

Idée: $a^n = a^{n/2} + a^{n/2}$

On va distinguer le cas pair et impair:
- $a^{2m} = a^2 * a^m$
- $a^{2m+1} = a^2 * a^m * a$

et $a^0 = 1$

1<sup>ière</sup> idée pour coder cela:
```ocaml
let rec exprap = fun a m -> if n = 0
    then 1 
    else
        let m = n/2 in if n mod 2 = 0
            then (exprap a m) * (exprap a m) 
            else a * (exprap a m) * (exprap a m)
```

Ce code termine, est correct mais a un défaut: il calcule deux fois `(exprap a m)`: c'est du gaspillage. On voudrait le calculer une seule fois.

Vraie `exprap`: cf annexe "exponentiation rapide récursive" On obtient ainsi une complexité en Ɵ( log<sub>2</sub>(n) )

### 5. Boucles

La récursivité permet de remplacer les boucles !

> [!NOTE]
> **Exemple**<br>
> cf annexe, factorielle: ces codes remplacent
> ```c
> int f = 1;
> for (int i = 2; i <= n; i++) {
>     f *= i;
> }
> return f;
> ```

## II - Concevoir un algo réc

Methode: il s'agit de trouver une réduction du problème à lui-même. <br>
Pour cela:
1. on suppose (soit) que l'on a un ami très intelligent qui peut résoudre les autres instances du prblm
1. on cherche un lien entre notre instance et d'autres instances 
1. on en déduit une méthode récursive qui utilise cette réduction
1. on cherche quand est-ce que cette réduction n'a pas de sens: ce sont les cas de base qu'il faut traiter à part: on détermine précisement ce qu'il faut alors faire

## III - Terminaison et Correction

C'est plus simple qu'en impératif car:
- il n'y a pas de boucles (ou peu)
- les variables sont immuables

### 1. Correction

C'est facile pour les fonctions non-rec (correc de fonction sans boucle)

Pour les fonctions récursives, on montre par réc sur leur(s) argument(s) qui varient que la spec est bien vérifiée

> [!NOTE]
> **Exemple**<br>
> Montrons que **1. Factorielle** est correcte<br>
> Elle doit renvoyer $n!$ pour tout $n \geq 0$<br>
> Montrons-la correcte par réc sur $n \geq 0$:
>
> **Initialisation :** si $n = 0$<br>
> fact 0 s'évalue à 1 d'après I-T-E (if then else) or $1 = 0!$ d'où l'initialisation
>
> **Hérédité :**<br>
> Supp fact correcte pour un certain $n \in \mathbb{N}$, montrons la correcte pour $n+1$<br>
> D'après le ITE, fact(n+1) vaut (n+1)*fact(n)<br>
> Or par H.R, fact(n) = n! Donc fact(n+1) = (n+1)! D'où l'hérédité

### 2. Terminaison

Il faut mq la suite d'appels réc termine. On procède comme pour les boucles, sauf que le variant varie d'un appel à l'autre

> [!NOTE]
> **Exemple**<br>
> n est un variant de fact car:
> - entier minorée par 0 (fact renvoie alors 1)
> str décroissant d'un appel au suivant puisque l'appel suivant est fait sur $n-1$ qui est < n

## IV - Compléxité

Il est important de distinguer:
- coût "local à l'appel en cours"
- coût des appels récursifs

### 1. Methode 1: équation

> [!NOTE]
> **Exemple**<br>
> Notons M(n) le nb de multiplications de fact n.<br>
> M vérifie:
> - M(0) = 0 et pour $n \geq 1$, M(n) = 1 + M(n-1)
>
> On résout et obtient M(n) = n

Généralement on a plutôt un $\theta$ : M(n) = $\theta$(1) + M(n-1)<br>
On remplace alors le $\theta$ par la cst qu'il cache et on résout M(n) = K + M(n-1). On obtient M(n) = $\theta$(n)

> [!CAUTION]
> **Rmq**<br>
> Généralement le cas de base est de compléxité $\theta$(1) et on l'omet