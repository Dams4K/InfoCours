<center><h1>OCaml - Olalah la galère</h1></center>

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
---

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
---

Un if / then / else est une exp: `if <bool> then <expr0> else <expr1>`

Où `expr0` et `expr1` ont le **même** type qui est le tupe du if / then / else

La valeur du if / then / else sera soit celle de `expr0` soit `expr1` (selon la valeur du `bool`)

On peut omettre le `else`. Cela équivaut à `else ()` càd `sinon rien`. Donc `expr0` doit être le type `unit`

### 3. Déclaration locale
---

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
---

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
---

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
> On a donc le type suivant ppour comp: `'b -> 'c -> 'a -> 'b -> 'a -> 'c`
