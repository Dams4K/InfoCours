# Complexité Spatiale


> [!TIP]
> **Déf**<br>
> La complexité spatiale d'une fonction est l'espace nécessaire à son fonctioannement
>
> On peut distinguer:
> - espace créé: espace (pule/tas mémoire) qu'il faut avoir disponible pour que la fonction puisse créer ses variables/allocations
> - espace utilisé: espace où la fonction fait à la fois des lectures et des écritures


> [!CAUTION]
> **Rmq**<br>
> - Un fonction peut utiliser de l'espace qu'elle n'a pas crée. Ex : un fonction prenant en argument un ptr vers une zone allouée
> - Dans le formalisme classque de la complexité spaciale(machine Turing) on compte l'espace utilisé ainsi:
>   - l'entrée doit ê en lecture seule et elle coûte 0 espace
>   - la sortie est en écriture seule et coûte 0 espace
>   - tout autre espace coûte autant que son nb de cases
> - Pour l'espace crée, attention à la pile mémoire:
> ```C
> for (int i = 0; i < p; i++) {
>   int x = 2*i;    
> }
> ```
> Ici, on crée p fois la variable `x` mais le mécanisme de pile mémoire fait que l'on utilise que 2 cases


> [!IMPORTANT]
> **Théorème**<br>
> Pour toute fonction/code, on a :<br>
> Espace créé <= Espace utilisé <= Temps<br>
> Preuve:
> - Tout espace crée est utilisé (ne serait-ce que pour l'initaliser), quitte à considérer le pire des cas.
> - Utiliser 1 espace demande 1 temps (le temps de lire/écrire)


> [!CAUTION]
> **Rmq (HP)**<br>
> Soit f une fonction à `l` lignes de code et utilisant `e` cases mémoires. Un **état** de la fonction consiste à donner
> - La valeur de ses `e` cases mémoires
> - La lgn qu'elle exécute

 Il y a donc 2^e * l états

 2^e = chq cases a 2 valeurs possibles

 Chque état est soit:
 - Final (return, arrête la fonction)
 - Non-final: mène à un autre état uniquement déterminé (on passe à la lgn suivante et la valeur des conditions de if/for/while est prévisible sachant la mémoire)

 Si une fonction, lors de sn existence passe 2 fois par le meme état non-final

 [lgn mem] - - - > - - - - - - > - - - - - - |<br>
 . . ^ - - - - - < - - - - - - - - - - - < - - - - |

Apres plein de choses, on retourne au même état



Dans ce cas, on a une boucle infini: on reboucle tjrs sur cet état (lgn, mem)

On en conclut que lors de son exec, la fonction parcout au plus `2`<sup>`e`</sup>` * l` états (sinon elle passerait 2x par le même)

Donc qu'elle s'execute en temps au plus 2^e*l

> [!CAUTION]
> **Rmq**<br>
> On note généralement E ou S la complexité spatiale
> - Conseil: qd on vous demande un complexité spatiale, indiquez espace crée et espace utilisé