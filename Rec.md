# Récursivité

### 1. La factorielle

On déf sur **N**: `n! = n(n-1)! si n > 0` $\hspace{25pt}$ `1 sinon`

C'est une déf réc! On réduit "calculer `n!`" à "calculer `(n-1)!`"

### 2. Triangle

Entrée: `n` un entier<br>
Tâche: Dessiner un triangle de `n` lignes d'étoiles

Une méthode rec est :
- écrire une ligne de `n` étoiles
- puis si `n > 1`, recursivement tracer un triangle de `n-1` lignes en dessous

### 3. Tours de Hanoï

Pour résoundre le problème on réduit le problème de déplacer `n` disques d'un emplacement à un autre à celui de déplacer `n-1` disques. Cette réduction n'a pas de sens si `n = 0`: c'est le cas de base qu'il faut gérer à part.

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
Entrée: a € **Z**<sup>*</sup>, n € **N**
Tâche: calculer a<sup>n</sup>

Idée: `a`<sup>`n`</sup> `=` `a`<sup>`n/2`</sup> `+` `a`<sup>`n/2`</sup>

On va distinguer le cas pair et impair:
- `a`<sup>`2m`</sup>` = a`<sup>`2`</sup> `*` `a`<sup>`m`</sup>
- `a`<sup>`2m+1`</sup>` = a`<sup>`2`</sup> `*` `a`<sup>`m`</sup>` * a`

et `a`<sup>`0`</sup>` = 1`

1^ière idée pour coder cela:
```ocaml
let rec exprap = fun a m -> if n = 0
    then 1 
    else
        let m = n/2 in if n mod 2 = 0
            then (exprap a m) * (exprap a m) 
            else a * (exprap a m) * (exprap a m)
```

Ce code termine, est correct mais a un défaut: il calcule deux fois `(exprap a m)`: c'est du gaspillage. On voudrait le calculer une seule fois.

Vraie `exprap`: cf annexe "exponentiation rapide récursive" On obtient ainsi une complexité en **TETA**( log<sub>2</sub>(n) )

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