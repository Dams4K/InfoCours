let affiche_int = fun x -> 
    let _ = print_int x in print_char '\n'

let affiche_bool = fun x -> match x with
    | true  -> print_string "true\n"
    | false -> print_string "false\n"

(* let _ = affiche_int 15
let _ = affiche_bool false *)

let is_empty = fun l -> match l with
    | [] -> true
    | h::t -> false

let l = 0::(1::[])
let l2 = []

(* let _ = affiche_bool (is_empty l)
let _ = affiche_bool (is_empty l2) *)

let hd = fun l -> match l with
    | [] -> failwith "no"
    | h::t -> h

(* let _ = affiche_int (hd l) *)
(* let _ = affiche_int (hd l2) *)

let rec print_int_list = fun l -> let _ = print_string "| " in match l with
    | [] -> print_string "\n"
    | h::t -> print_int h ; print_string " | " ; print_int_list t

(* let _ = print_int_list l *)

let rec length = fun l -> match l with
    | [] -> 0
    | h::t -> 1 + length t

(* let _ = affiche_int (length l)
let _ = affiche_int (length [1; 3; 5; 7; -5; -6; 5]) *)

let rec int_sum = fun l -> match l with
    | [] -> 0
    | h::t -> h + int_sum t

(* let _ = affiche_int (int_sum l)
let _ = affiche_int (int_sum [1; 3; 5; 7; -5; -6; 5]) *)

let rec mem = fun x l -> match l with
    | [] -> false
    | h::t -> x = h || mem x t

(* let _ = affiche_bool (mem 1 [1; 3; 5; 7; -5; -6; 5])
let _ = affiche_bool (mem 10 [1; 3; 5; 7; -5; -6; 5]) *)

let rec append = fun l1 l2 -> match l1 with
    | [] -> l2
    | h::t -> h::(append t l2)

(* let _ = print_int_list (append [0; 2; 4] [1; 3; 5]) *)

let rec print_even = fun l -> match l with
    | [] -> print_string "\n"
    | h::t when h mod 2 = 0 -> let _ = print_int h in print_string " " ; print_even t
    | h::t -> () ; print_even t

(* let _ = print_even [1; 3; 5; 7; -5; -6; 5] *)

(* ------------------------ *)

let rec exists = fun cond l -> match l with
    | [] -> false
    | h::t -> cond h || exists cond t

let tmp = fun x -> x = 1

(* let _ = affiche_bool (exists tmp [2; 3; 4; 5; 1; 6])
let _ = affiche_bool (exists tmp [2; 3; 4; 5; 0; 6]) *)

let rec for_all = fun cond l -> match l with
    | [] -> false
    | h::[] -> cond h
    | h::t -> cond h && for_all cond t

(* let _ = affiche_bool (for_all tmp [2; 3; 4; 5; 1; 6])
let _ = affiche_bool (for_all tmp [1; 1; 1; 1; 1; 1; 1]) *)

let tmp = fun x -> x mod 2 = 0

(* let _ = print_string "---\n" *)

(* let _ = affiche_bool (tmp 6)
let _ = affiche_bool (tmp 5) *)

let rec filter = fun cond l -> match l with
    | [] -> []
    | h::t when cond h -> h::(filter cond t)
    | h::t -> filter cond t

(* let _ = print_int_list (filter tmp [1; 2; 4; 5; 36; 7; 8]) *)

(* F - FONCTIONS AVANCÉES *)

let rec map = fun f l -> match l with
    | [] -> []
    | h::t -> (f h)::(map f t)

let double = fun x -> x*2

(* let _ = print_int_list (map double [4; 5; 3; 98; 2]) *)

let rec iter = fun f l -> match l with
    | [] -> ()
    | h::t -> f h ; iter f t

(* let _ = iter affiche_int [4; 3; 5; 6; 7; 8] *)

(* G - Comparaisons et Tris *)

(* let f_comparaison = fun a b -> if a < b
    then -1 
    else if a > b
        then 1
        else 0 *)

let f_c = fun a b -> if a < b then -1 else if a = b then 0 else 1


let rec compare = fun f l1 l2 -> match (l1, l2) with
        | ([], t::h) -> -1
        | (t::h, []) -> 1
        | ([], []) -> 0
        | (h1::t1, h2::t2) -> if h1 = h2
            then compare f t1 t2
            else if f h1 h2 
                then -1
                else 1

(* let rec compare = fun f l1 l2 -> match (l1, l2) with
    | (h1::t1, h2::t2) -> f h1 h2 + compare f t1 t2
    | (h1::t1, []) -> 0
    | ([], h2::t2) -> 0
    | ([], []) -> 0 *)



(* let _ = affiche_int (compare f_c [1; 6; 3; 4] [5; 2; 7; 8]) *)

(* let rec sort = fun f l -> match l with
    | [] -> []
    | t::h -> h::t *)

(* let rec sort = fun f l1 l2 -> match (l1, l2) with
    | (h1::t1, h2::t2) -> if f h1 h2 <= 0
        then h1::(h2::(sort f t1 t2))
        else h2::(h1::(sort f t1 t2))
    | (h1::t1, []) -> l1
    | ([], h2::t2) -> l2
    | ([], []) -> []

let _ = aff *)