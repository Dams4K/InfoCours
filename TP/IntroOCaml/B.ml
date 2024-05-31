let print_bool = fun x -> if x then print_string "true\n" else print_string "false\n"

let implique = fun a b -> (not a) || (a && b)

let _ = print_bool (implique true false)

let g = fun x -> x+1
let f = fun x -> x*2

let comp = fun g f -> let _ = fun x -> g(f(x))

let _ = print_int ( (comp(f g) x) )
let _ = print_string "\n"

(* let f = fun x -> x*10

let q9a = fun f -> ((f 0) + (f 1))/2

let _ = print_int (q9a f)
let _ = print_string "\n"

let q9b = fun f -> f * f

let _ = print_int ((q9b f) 5)
let _ = print_string "\n" *)

(* let q9c = fun f -> f(f())
let q9d = fun f -> let g = fun x -> f(x+1)
let q9e *)