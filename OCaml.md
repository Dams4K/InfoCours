<center><h1>OCaml - Oulaah, c'est trop compliqué poour mwa</h1></center>

## Intro

OCaml est un langage :
- Fonctionnel: les fonctions sont un élément de 1<sup>er</sup> plan. On peut manipuler comme des variables les fonctions.
    
    Plus généralement, on programme en décrivant une (suite d') expression à évoluer.

    > [!WARNING]
    > Les variables sont non-muables !!
- Fortement typé: une variable ne peut pas changer de type.
- Statiquement typé: une variable ne peut pas changer de type
- Impur: on peut faire "comme du c" avec des "variables muables" *(au S2)*
- **Compilé**, mais qui dispose d'un interpréteur pour tester des bouts de code

## I - Structure

Un programme OCaml est une suite de **phrases OCaml** qui peuvent être:
- Déclaration d'exception *(au S2)*
- Déclaration des type *(cf plus tard)*
- Déclaration de var global

La fin d'une phrase est non-ambigüe: il n'y a **pas** de symbole de fin

Une phrase déclarant une var global est de la forme:
```ocaml
let <id> = <expr>
```
On ne précise pas le type: le compilateur l'infère !

### 1. Expression


En OCaml "tout est expression" (sauf les phrases) càd que sont des expressions:
- entiers, flottants et leurs opérations
- bool et leurs opérations
- tout les types de bases et leurs opérations
- fonctions
- un if / then / else

> [!CAUTION]
> \- Certaines variables (surtt les foncitons) peuvent avoir plusieurs types possibles: on parle de polymorphisme<br>
> Ex: `let f = fun x -> x`<br>
> type : $\hspace{42pt}$ `'a -> 'a`
> 
> \- Certaines expressions n'ont "pas de valeurs". On leur donne le type et la valeur `()`

> [!IMPORTANT]
> **Théorème**<br>
> \- Le type d'une expression est vérifiée avant de l'évaluer <br>
> \- Une expression est implicitement parenthésée à gauche d'abord

### 2. Conditionnelles


Un if / then / else est une exp: `if <bool> then <expr0> else <expr1>`

Où `expr0` et `expr1` ont le **même** type qui est le tupe du if / then / else

La valeur du if / then / else sera soit celle de `expr0` soit `expr1` (selon la valeur du `bool`)

On peut omettre le `else`. Cela équivaut à `else ()` càd `sinon rien`. Donc `expr0` doit être le type `unit`

### 3. Déclaration locale


Pour rendre le code plus lisible, on peut créer des variables locales avec l'expr 
```ocaml
let id = <expr0> in <expr1>
```

> [!WARNING]
> C'est une expression pas une phrase.

On calcule **une fois** expr<sub>0</sub>, puis on calcule expr, en y remplaçant `id` par la valeur calculée de expr<sub>0</sub>. Le type et la valeur obtenus pour expr<sub>1</sub> sont le type est la valeur du `let in`. Un autre intérêt du `let in` est de permettre d'enchainer l'éval d'expr.

```ocaml
let affiche_int = fun x -> let _ = print_int x in print_char "\n"
```

## II - Fonctions

EN OCaml, les fonctions sont des **expressions**? Elles sont de la forme

```ocaml
fun <x0> <x1> <x2> ... -> <expr>
```
`expr` peut utiliser `x0 x1 x2 ...`

Si `arg`<sub>`0`</sub> `arg`<sub>`1`</sub> `arg`<sub>`2`</sub> `... arg`<sub>`k-1`</sub> sont de type `T`<sub>`0`</sub> `T`<sub>`1`</sub> `T`<sub>`2`</sub> `... T`<sub>`k-1`</sub> et que expr est de type `T`<sub>`e`</sub>, alors cette fonction est de type `T`<sub>`0`</sub> `-> T`<sub>`1`</sub> `-> T`<sub>`s`</sub> `-> ... -> T`<sub>`k-1`</sub> `-> T`<sub>`e`</sub>

### 1. Curryfication


*(Interlude maths)*

On peut transformer une fonction à plusieurs arg en succession de fonctions à un seul argument.

Ex sit `f: (x, y) -> x+y` f est "équivalente" à : `g: x -> (y -> x+y)`

Ici, g est la fonction qui a `x` associe `f(x, ?)`: c'est l'application partielle de f en fixant son premier argument.

Avec g, on voit le fait de calculer `f(x, y)` comme:
1. Calculer `f(x, ?)`
2. renvoyer `f(x, ?)(y)`

> [!NOTE]
> **Exemple**<br>
> `f(3, 2) = f(3, ?)(2)`
> <br>
> $\hspace{49pt}$ y -> 3+y
> <br>
> $\hspace{38pt}$ `= 5`

Ce procédé de transformation s'appelle la curryfication

> [!NOTE]
> **Exemple**<br>
> **Z**<sup>3</sup> -> **Z**
> `f: (x, y, z) -> z`<sup>`x-y`</sup> correspond à `x -> (y -> (z -> z`<sup>`x+y`</sup>`))`

*(Fin interlude)*

En Ocaml, toutes les fonctions sont curryfiées. Càd:
-  `fun` `x`<sub>`0`</sub> `x`<sub>`1`</sub> `...` `x`<sub>`k-1`</sub> `-> expr` est un raccourci pour `fun` `x`<sub>`0`</sub> `-> (fun` `x`<sub>`1`</sub> `-> ... (fun` `x`<sub>`k-1`</sub> `-> expr)...))`
- on peut donc faire des applications partielles de fonction
- on comprend le type:
    <br>
    `fun` `x`<sub>`0`</sub> `-> (fun` `x`<sub>`1`</sub> `-> ... (fun` `x`<sub>`k-1`</sub> `-> expr)...))`
    
    `T`<sub>`0`</sub> `-> (` `T`<sub>`1`</sub> `-> ... (` `T`<sub>`k-1`</sub> `-> T`<sub>`e`</sub> `)...))`

    Les types sont implicitement parenthésés de droite à gauche

### 2. Ordre supérieur


Une fonction d'ordre supérieur est une fonction qui prend en argument une fonction

> [!NOTE]
> **Exemple**
> 
> ```ocaml
> let comp = fun g f -> fun x -> g (f x)
> ```
> `x` n'a pas de type imposé: il est polymorphe donc `'a`
> 
> Regardons le type de `f x`. Son type n'est pas imposé: `'b` (pas forcément le même type que x)
>
> Donc `f: 'a -> 'b`<br>
> et $\hspace{10pt}$ `g: 'b -> ?`
>
> Enfin, le type de sortie de g n'est pas imposé: `g: 'b -> 'c`
>
> On a donc le type suivant pour comp: `'b -> 'c -> 'a -> 'b -> 'a -> 'c`

### 3. Récursivité mutuelle

En maths, on peut définir: $u_0 = v_0 = 0$ et pour $n \geq 1,$<br>
$u_n = v_{n-1}+1$<br>
$v_n = 3u_{n-1}$

En info, on dit que de tels $u_n$ et $v_n$ sont **mutuellement récursives**.

On peut faire de la rec en mut en OCaml:
```ocaml
let rec f = fun ... (* def de f, qui peut utiliser g *)
    ...
    and g = fun ... (* def de g, qui peut utiliser f *)
        ...
```

### 4. Ordre d'évaluation 

En OCaml (comme en C), les arguments d'une fonction sont évaluées avant d'executer la fonction (car on passe leur valeur).

En particulier, si les arguments ont des effets secondaires, ils ont lieu avant la fonction

## III - Types plus avancés et filtrage par motif

### 1. Types produits, let destructurant

> [!TIP]
> **Déf**<br>
> On appelle type produit un type permettant de manipuler des n-uplets

> [!NOTE]
> **Exemple**
> ```ocaml
> int * int (* 2 uplets d'entiers *)
> int * string (* couple dont la 1iere coord est int et la seconde string *)
> ```

On peut faire le produit d'un nombre fixé arbitraire de types

> [!NOTE]
> **Exemple**
> ```ocaml
> int * bool * string
>```

> [!CAUTION]
> le types des coords est fixé: `int * int` ne peut pas contenir `(3.5, 4.0)`

Un n-uplets se note $(x_0, x{_1}, ... , x_{n-1})$

Réciproquement, en OCaml, s'il y a des virgules, c'est que c'est un uplet

> [!IMPORTANT]
> **Propiété**<br>
> Si $\tau$ est un type produit contenant des k-uplets, alors `let (x`<sub>`0`</sub>`, x`<sub>`1`</sub>`, ..., x`<sub>`k-1`</sub>`) = uplet` permet d'accéder aux différents coords de uplet. On parle de let déstructurant.

### 2. Déclaration de type

En OCaml, on peut déclarer un type `t` via la phrase `type y = ...`

> [!NOTE]
> **Exemple**
> ```ocaml
> type t = int
> type u = bool * string * char
>```
>
> ```ocaml
> let f = fun x y -> (x, y)
> let g = fun (x y) -> (x, y)
> ```
> `f: 'a -> 'b -> 'a * 'b`<br>
> `f: 'a * 'b -> 'a * 'b`

### 3. Filtrage par motif

> [!TIP]
> **Déf**<br>
> Le filtrage permet de faire une disjonction de cas sur la forme de la valeur d'une expression. Il s'écrit :
> ```ocaml
> match expr with
>   | motif0 -> e0
>   | motif1 -> e1
>   ...
> ```
> où `motif0`, `motif1`, ..., sont des formes possibles pour la valeur de `expr`; et `e0`, `e1`, ..., sont les expr à évaluer dans ces cas

> [!NOTE]
> **Exemple** cf annexe

> [!IMPORTANT]
> **Propriété**<br>
> - Un filtrage est une expression.<br>
> En particulier, il a un type:le type de `e0`, `e1`, `e2`... doivent être les mêmes. Sa valeur est celle de `e0` ou `e1` etc selon l'execution.
> - Un filtrage doit couvrir tous les cas possibles (une expression **doit** avoir une valeur)
> - Les motifs sont testés dans l'ordre<br>
> Dès qu'un motif valide est trouvé, le filtrage s'arrête
> - Un motif peut se comporter comme un let destructurant

> [!CAUTION]
> `_` est un joker qui correspond à "n'importe quoi !"

### 4. Types sommes

> [!TIP]
> **Déf**<br>
> Un type énuméré est un type qui ne peut prendre ses valeurs que dans un ensemble fixé.<br>
> On note 
> ```ocaml
> type 𝜏 = Val0 | Val1 | ... | Val(n-1)
> ```
> Un élement de $\tau$ vaut toujours l'un des Val<sub>i</sub>

> [!NOTE]
> **Exemple**
> ```ocaml
> type couleur = Carreau | Pique | Coeur | Trèfle
> ```

> [!CAUTION]
> **Attention**
> - Les ma<sub>j</sub>uscules sont **obligatoires** au début des Val<sub>i</sub>
> - Le filtrage est très pratique sur de tels types

> [!TIP]
> **Déf**<br>
> On appelle Val<sub>i</sub> des constructeurs

> [!IMPORTANT]
> **Propriété & Déf**<br>
> Un constructeur peut prendre un argument. On parle alors de type somme.
>
> La syntaxe est `type 𝜏 = Val`<sub>`0`</sub>` of int | ...` Val<sub>0</sub> attend un `int`

> [!NOTE]
> **Exemple**
> `plus_expr` (annexe)

> [!CAUTION]
> **Rmq**<br>
> - $\neq$ constructeurs peuvent attendre $\neq$ types
> - Si Val<sub>i</sub> est un constructeur on l'utilise "comme une fonction"

> [!NOTE]
> **Exemple**<br>
> `Entier 3`<br>
> *^ constructeur*<br>
> `plus_expr` obtenue en "appliquant" `Entier` à 3

> [!Important]
> **Théorème**<br>
> Un type somme peut être récursif

> [!NOTE]
> **Exemple**
> ```ocaml
> type Entier = 
> | Zero
> | Succ of Entier
> ```
> *(càd un entier est soit 0 soit n+1 pour n un entier)*

Les listes OCaml sont un tel type somme rec défini par:
- soit une liste est vide
- soit elle comment par un élément ("tête") puis se continue en une autre liste ("queue")

Les deux cas se notent:
```ocaml
[] (* liste vide *)
t::q (* tête suivie de queue *)
```

> [!NOTE]
> **Exemple**
> ```ocaml
> 3::(2::(1::[]))
> ```
> est la liste contenant 3 puis 2 puis 1.<br>
> On peut aussi la noter `[3; 2; 1]` (accepté par le compilateur) -> cf TD

