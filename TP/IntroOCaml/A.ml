let print_bool = fun x -> if x then print_string "true\n" else print_string "false\n"

let cst_0 = fun x -> 0
let id = fun x -> x
let parite = fun x -> x mod 2 = 0

let _ = if parite 5 then print_string "Paire\n" else print_string "Impaire\n"
let _ = if parite 4 then print_string "Paire\n" else print_string "Impaire\n"

let min = fun x y -> if x < y then x else y

let _ = print_int (min 4 6)
let _ = print_string "\n"

let min_3 = fun x y z -> if (min x y) < z then (min x y) else z

let _ = print_int (min_3 4 12 6)
let _ = print_string "\n"

let _ = print_int (min_3 12 3 6)
let _ = print_string "\n"

let _ = print_int (min_3 9 9 9)
let _ = print_string "\n"

let bissextile = fun x -> (x mod 4 = 0) && not (x mod 100 = 0) || (x mod 400 = 0)

let _ = if bissextile 2016 then print_string "Bisex\n" else print_string "NoBisex\n"
let _ = if bissextile 2019 then print_string "Bisex\n" else print_string "NoBisex\n"

let nb_positif = fun x -> x >= 0

let _ = print_bool (nb_positif 5)
let _ = print_bool (nb_positif (-3))
let _ = print_bool (nb_positif 0)