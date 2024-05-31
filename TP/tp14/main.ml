type 'a tree = Nil | Node of 'a * 'a tree * 'a tree
let arbre_exemple = Node(42, Node(3, Node(5, Nil, Nil),Node(7, Nil, Nil)), Node(24, Nil, Nil))

let rec hauteur t = match t with
| Nil -> -1
| Node(v, g, d) -> 1 + max (hauteur g) (hauteur d)

let rec taille t = match t with
| Nil -> 0
| Node(v, g, d) -> 1 + taille g + taille d

let rec somme t = match t with
| Nil -> 0
| Node(v, g, d) -> v + somme g + somme d

let rec affiche_prefix t = match t with
| Nil -> ()
| Node(v, g, d) -> let _ = print_int v in let __ = print_char ' ' in let ___ = affiche_prefix g in affiche_prefix d

let rec affiche_infix t = match t with
| Nil -> ()
| Node(v, g, d) -> let _ = affiche_infix g in let __ = print_int v in let ___ = print_char ' ' in affiche_infix d

let rec affiche_postfix t = match t with
| Nil -> ()
| Node(v, g, d) -> let _ = affiche_postfix g in let __ = affiche_postfix d in let ___ = print_int v in print_char ' '

let rec peigne_gauche n = if n = 0 then Nil else Node(n, peigne_gauche(n-1), Nil)

let rec peigne_droit m = let rec r_peigne_droit n = if n = m then Nil else Node(n+1, Nil, r_peigne_droit(n+1)) in r_peigne_droit 0

let parfait h = let rec r_parfait k = if k = h then Nil else Node(h-k, r_parfait (k+1), r_parfait (k+1)) in r_parfait (-1)

let rec est_strict t = match t with
| Nil -> true
| Node(_, Node(a, b, c), Nil) -> false
| Node(_, Nil, Node(a, b, c)) -> false
| Node(_, g, d) -> (est_strict g) && (est_strict d)

type 'a strict = Feuille of 'a | Noeud of 'a * 'a strict * 'a strict

let rec hauteur_strict t =
  match t with
  | Feuille(_) -> 0
  | Noeud(_, g, d) -> 1 + max (hauteur_strict g) (hauteur_strict d)

let rec nb_feuilles t =
  match t with
  | Feuille(_) -> 1
  | Noeud(_, g, d) -> nb_feuilles g + nb_feuilles d

let rec nb_noeuds_internes t =
  match t with
  | Feuille(_) -> 0
  | Noeud(_, g, d) -> 1 + nb_noeuds_internes g + nb_noeuds_internes d

let rec profondeur_min t =
  match t with
  | Feuille(_) -> 0
  | Noeud(_, g, d) -> 1 + min (profondeur_min g) (profondeur_min d)

let diff_max t = hauteur_strict t - profondeur_min t