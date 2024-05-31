(*           Implémentation des arbres rouges noirs           *)
(* Sujet à trous version Normal *)



(* Rappel : la documentation est dans l'interface. *)



type couleur =  Rouge 
              | Noir

type 'a arn =  Nil
             | Node of couleur * 'a arn * 'a * 'a arn



(* Initialisateurs *)

let empty () = 
  Nil


(* Accès aux attributs / propriétés *)


(* Propriétés d'un noeud*)

let etiquette = function
  | Node (_,_,x,_) -> x
  | _ -> failwith "etiquette Nil"

let gauche = function
  | Node(_, g,_, _) -> g
  | _ -> failwith "gauche Nil"

let droite = function
  | Nil -> failwith "droite Nil"
  | Node(_, _, _, d) -> d

let est_rouge = function
  | Nil -> false (* les feuilles sont Noires *)
  | Node(c, _, _, _) -> c = Rouge

let est_noir = function
  | Nil -> true (* les feuilles sont Noires *)
  | Node(c, _, _, _) -> c = Noir


(* Propriétés d'un arbre *)

let rec hauteur = function
  | Nil -> -1
  | Node(_, g, _, d) -> (max (hauteur g) (hauteur d)) + 1

(* Petite technicité : notre hauteur est définie par
   le nb d'arêtes, et notre hauteur_noire par un nb de noeuds.
   D'où les initialisations différentes. *)

let rec hauteur_noire = function
  | Nil -> 0
  | Node (Rouge, g, _, d) -> (hauteur_noire d)
  | Node (Noir, g, _, d) -> (hauteur_noire d) + 1

let rec recherche x t = match t with
  | Nil -> false
  | Node(_, _, v, _) when x = v -> true
  | Node(_, _, v, d) when x > v -> recherche x d
  | Node(_, g, v, _) when x < v -> recherche x g

let rec minimum = function
  | Nil -> failwith "Non"
  | Node(_, Nil, x, _) -> x
  | Node(_, g, _, _) -> minimum g

let rec maximum = function
  | Nil -> failwith "Non"
  | Node(_, _, x, Nil) -> x
  | Node(_, _, _, d) -> maximum d

(* Transformateurs *)


(* Recoloriages *)

let devient_rouge = function
  | Nil -> failwith "devient_rouge Nil"
  | Node (_, g, x, d) -> failwith "TODO"

let devient_noir = function
  | Nil -> failwith "devient_noir Nil"
  | Node (_, g, x, d) -> failwith "TODO"


(* Rotations *)

(* Notations :
           y                          x
          / \         droite         / \
         x   c        ----->        a   y
        / \           <-----           / \
       a   b	        gauche          b   c    
*)

let rotation_droite t =
  failwith "TODO" 

let rotation_gauche t = match t with
  | Node (col_x, a, x, Node (col_y, b, y, c)) ->
      Node (col_y, Node (col_x, a, x, b), y, c)
  | _ -> failwith "rot gauche sur arbre vide ou vide à droite"



(* Transformateurs *)


(* Insertion *)

(* Rappel : les notations sont dans l'interface-énoncé *)


let corrige_rouge t = 
  (* On utilise les fonctions auxiliaires précédentes :
   détermine le cas et appelle la bonne fonction.
   Faire des schémas !!
  *)
  match t with
  (* Cas 1. On a un enchainement R-R à corriger *)
  (* | _ -> failwith "TODO : corriger les 4 cas d'enchainement R-R" *)
  | Node(Noir, Node(Rouge, Node(Rouge, a, x, b), y, g), z, d) -> 
  | Node(Noir, Node(Rouge, a, x, Node(Rouge, b, y, g)), z, d) -> 
  | Node(Noir, a, x, Node(Rouge, Node(Rouge, b, y, g), z, d)) ->
  | Node(Noir, a, x, Node(Rouge, b, y, Node(Rouge, g, z, d))) ->
  (* Sinon : pas de problème ! On renvoie donc l'arbre tel quel.*)
  | _ -> t

let rec insere_aux x t = match t with
  | Nil -> failwith "TODO"
  | Node (col_y, g, y, d) ->
      if x = y (* x est déjà présent *)
      then t
      else if x < y (* on doit insérer à gauche *)
      then corrige_rouge (Node (col_y, insere_aux x g, y, d))
      else (* on doit insérer à droite *)
           corrige_rouge (Node (col_y, g, y, insere_aux x d))


let insere x t =
  failwith "TODO"