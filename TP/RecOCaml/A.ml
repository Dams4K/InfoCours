let rec fact = fun x -> if x = 0 
      	then
			1 
      	else
          	x*(fact(x-1))

let _ = print_int(fact(6))
let _ = print_string("\n")

let rec ln_stars = fun x -> if x = 1 then print_string("*\n") else let _ = print_string("*") in ln_stars (x-1)

(* let _ = ln_stars 5 *)

let rec triangle_bas = fun x -> if x > 1 then let _ = ln_stars(x-1) in triangle_bas(x-1)
let rec triangle_haut = fun x -> if x > 1 then let _ = triangle_haut(x-1) in ln_stars(x-1)

(* let _ = triangle_bas 6
let _ = print_string "\n"
let _ = triangle_haut 6 *)

(* let rec square = fun x -> let y = x in if x = 0 && y = 0 then let _ = print_string "*\n" in square 4 else if y = 0 then print_string "*\n" else ln_stars x *)

(* let rec carre_creux = let size = x in fun x -> if x = 0 then ln_stars size else carre_creux(x-1) *)

(* let rec carre_creux = fun size -> let rec aaa = fun x -> if x = 0 then ln_stars size else let _ = ln_stars (x-1) in aaa size in aaa size *)
(* let rec carre_creux = fun size -> let aaa = fun x -> print_int x in aaa size *)

(* let rec carre_creux = fun size -> let x = size in if x > 0 then carre_creux(size-1) *)
let carre = fun size -> let rec lavraierec = fun y -> if y = 0
	then ln_stars size
	else let _ = ln_stars size in lavraierec (y-1) in lavraierec (size-1)


let rec ln_stars_2 = fun x -> if x = 1 then print_string("*\n") else let _ = print_string(" ") in ln_stars_2 (x-1)


let carre_creux = fun size -> let rec lavraierec = fun y -> if y = 0 || y = (size-1)
	then if y == 0
		then ln_stars size
		else let _ = ln_stars size in lavraierec (y-1)
	else let _ = print_string "*" in let __ = ln_stars_2 (size-1) in lavraierec (y-1) in lavraierec (size-1)

let _ = carre_creux 3
let _ = carre_creux 4
let _ = carre_creux 5
let _ = carre_creux 6

(* let rec somme_f = fun f n -> if n >= 1 then (f n) + somme_f(n-1) else f 0 *)

(* let f = fun x -> x

let _ = print_int somme_f f 5 *)