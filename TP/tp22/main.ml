let rec ligne n c = if n > 0 then let _ = print_string c in ligne (n-1) c else print_string "\n"

let rec triangle n c = if n > 0 then let _ = ligne n c in triangle (n-1) c else ()

let incr x = x := !x + 1

let mystere l =
  let count = ref 0 in
  let rec mystere_loop l = match l with
  | [] -> ()
  | h::t -> let _ = incr count in mystere_loop t 
  
  in
  let _ = mystere_loop l in !count

let mystere_pair l =
  let count = ref 0 in
  let rec mystere_loop l = match l with
  | [] -> ()
  | h::t when h mod 2 = 0 -> let _ = incr count in mystere_loop t
  | h::t -> mystere_loop t
  
  in
  let _ = mystere_loop l in !count

let double_int_array a =
  let n = Array.length a in
  let rec d_i_a a i =
    if i >= 0 then 
      let _ = a.(i) <- a.(i) * 2 in d_i_a a (i-1)
    else ()
  in d_i_a a (n-1)

let tri_bulle a =
  for i = 1 to Array.length a do
    for j = 0 to Array.length a - i-1 do
      if a.(j+1) < a.(j) then
        let tmp = a.(j) in
        let _ = a.(j) <- a.(j+1) in
        a.(j+1) <- tmp
    done
  done

let abs n =
  if n >= 0 then n
  else -n

let q23 a =
  let m = ref 0 in
  let _ =
    for i = 0 to Array.length a -2 do
      let v = abs (a.(i)-a.(i+1)) in
      if v > !m then
        m := v
    done
  in !m


let q26 a =
  print_string "| ";
  for i = 0 to Array.length a -1 do
    print_int a.(i) ; print_string " | "
  done ; print_char '\n'