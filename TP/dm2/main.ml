let lst_prefixes l =
  let rec construit_prefixes l pref_en_cours pref_deja_calcules =
    match l with
    | [] -> pref_deja_calcules
    | h::t -> let pref = List.append pref_en_cours [h] in
                construit_prefixes t pref (pref::pref_deja_calcules)
  in
  construit_prefixes l [] []

let lst_facteurs l =
  let rec facteurs_aux l = match l with
  | [] -> []
  | h::t -> (lst_prefixes l)::(facteurs_aux t)
  in
  List.flatten (facteurs_aux l)


let somme_facteurs l =
  let rec somme l =
    match l with
    | [] -> 0
    | h::t -> h + (somme t)
  in
  List.map somme (lst_facteurs l)

  
let rec max_l l = 
  match l with
  | [] -> failwith "Vide"
  | h::[] -> h
  | h::t -> let t_max = (max_l t) in if h > t_max then h else t_max

(* partie 2 *)

let rec s_prefixe l =
  match l with
  | [] -> failwith "Vide"
  | h::[] -> h
  | h::t -> max h (h + s_prefixe t)

let rec s_facteur_lent l = match l with
| [] -> failwith "Vide"
| [h] -> h
| h::t -> max (s_prefixe l) (s_facteur_lent t)