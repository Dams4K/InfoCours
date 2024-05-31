open Francais
open Hashtbl
open List

(* let () = affiche_arbre arbre_francais; print_newline () *)

(* a = 1100  ' ' = 10 *)

let rec mirroir s =
  let n = ref "" in
  for i = String.length s-1 downto 0 do
    n := !n ^ (String.make 1 s.[i])
  done;
  !n

let ajoute_s t = t ^ (String.make 1 's')

let _ = print_string (mirroir "Salut"); print_newline ()
let _ = print_string (ajoute_s "texte"); print_newline ()

let ht = Hashtbl.create 1
let _ = Hashtbl.add ht 'z' 15

let valeur_z ht = match Hashtbl.find_opt ht 'z' with
| None -> ()
| Some v -> print_int v; print_newline ()

let valeur_ x ht = match Hashtbl.find_opt ht x with
| None -> ()
| Some v -> print_string v; print_newline ()

let _ = valeur_z ht

let arbre_to_dico a =
  let tbl = Hashtbl.create 30 in
  let rec aux a c =
    match a with
    | N(g, d) -> aux g (c ^ "0"); aux d (c ^ "1")
    | F(v) -> Hashtbl.add tbl v c
  in aux a "";
  tbl

let _ = valeur_ 'h' (arbre_to_dico arbre_francais)

let compresse_message m a =
  let tbl = arbre_to_dico a in
  let mc = ref "" in
  for i = 0 to String.length m -1 do
    mc := !mc ^ Hashtbl.find tbl m.[i]
  done;
  !mc

let _ = print_string (compresse_message "hello world" arbre_francais); print_newline ()

let decompresse_message mc a =
  let m = ref "" in
  let i = ref 0 in
  let rec f a =
    match a with
    | N(g, d) -> i := !i+1; if mc.[!i-1] == '1' then f d else f g
    | F(v) -> m := !m ^ (String.make 1 v)
  in
  while !i < String.length mc do
    let _ = f a in ()
  done;
  !m

(* let _ = print_string (decompresse_message mystere arbre_francais); print_newline ()
let _ = print_string (decompresse_message mystere2 arbre_francais); print_newline ()
let _ = print_string (decompresse_message mystere3 arbre_francais); print_newline () *)


let codage_huffman l =
  let rec to_a l =
    match l with
    | (e, f)::t -> (F(e), f)::(to_a t)
    | [] -> []
  in let l = ref (to_a l) in

  let f a b =
    match a, b with
    | (al, af), (bl, bf) when af < bf -> -1
    | (al, af), (bl, bf) when af = bf -> 0
    | (al, af), (bl, bf) when af > bf -> 1
    | _, _ -> 0
  in

  while List.length !l > 1 do
    let _ = l := List.sort f !l in
    let (l0, f0) = List.nth !l 0 in
    let (l1, f1) = List.nth !l 1 in
    
    let n = N(l0, l1) in
    let f = f0 +. f1 in

    let lt = (List.tl (List.tl !l)) in
    let ln = [(n, f)] in l := List.concat [ln; lt]
    (* let l = List.concat [[(n, f)] ] in () *)
  done;
  let (l, f) = List.nth !l 0 in l

let _ = affiche_arbre arbre_francais; print_newline ()
let _ = affiche_arbre (codage_huffman lettres_avec_frequences); print_newline ()

let trouve_frequences s =
  for i = 0 to String.length s do
    