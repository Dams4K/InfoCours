type 'a abr = Nil | N of 'a abr * 'a * 'a abr

let t = N(
  N(Nil, 5, Nil),
  10,
  N(
    N(Nil, 15, Nil),
    20,
    Nil
  )
)

let rec mem_arbre tree x = match tree with
| Nil -> false
| N(g, v, d) -> x = v || if v > x then mem_arbre g x else mem_arbre d x

let rec insere_arbre tree x = match tree with
| Nil -> N(Nil, x, Nil)
| N(_, v, _) when v = x -> tree
| N(g, v, d) when v < x -> N(g, v, insere_arbre d x)
| N(g, v, d) when v > x -> N(insere_arbre g x, v, d)

let rec insere_arbre_l tree l = match l with
| [] -> tree
| h::t -> insere_arbre_l (insere_arbre tree h) t


let ordonne_abr tree = 
  let rec r_oa tree l = match tree with
  | Nil -> []
  | N(g, v, d) -> (r_oa g l) @ [v] @ (r_oa d l)
in r_oa tree []

let list_to_abr l = insere_arbre_l Nil l

let trie_list l = ordonne_abr (list_to_abr l)

let rec min_abr tree = match tree with
(* | Nil -> () *) (* ??? *)
| N(Nil, v, d) -> v
| N(g, v, d) -> min_abr g

let rec max_abr tree = match tree with
| N(g, v, Nil) -> v
| N(g, v, d) -> min_abr d

let rec supprime_max tree = let m = max_abr tree in match tree with
| Nil -> tree
| N(g, v, _) when v = m -> g
| N(g, v, d) -> N(g, v, supprime_max d)

let rec supprime_element tree x = if mem_arbre tree x then
  match tree with
  | N(g, v, d) when v < x -> supprime_element d x
  | N(g, v, d) when v > x -> supprime_element g x
  
else tree