(** Plan du TP :
  - coder la fonction de simplif de Quine

  - coder Quine
*)

type prop =
  | Const of bool   (* true représente top, false bottom *)
  | Var of int      (* i représente x_i *)
  | Non of prop
  | Et of prop*prop
  | Ou of prop*prop
  | Implique of prop*prop
  | Equivaut of prop*prop

let ex =
  Implique ( 
    Et (Non (Var 0), Var 1),
    Ou (Et (Non (Var 0), Var 2), Et (Var 1, Var 2))
  )

let affiche_formule f =
  let rec affiche_formule_aux f =
    match f with
    | Const b -> if b then print_string "V" else print_string "F"
    | Var i -> Printf.printf "x_%d" i
    | Non p -> print_string "Non ("; affiche_formule_aux p; print_string ")"
    | Et (p,q) -> print_string "("; affiche_formule_aux p;
                  print_string ") Et ("; affiche_formule_aux q; print_string ")"
    | Ou (p,q) -> print_string "("; affiche_formule_aux p;
                  print_string ") Ou ("; affiche_formule_aux q; print_string ")"
    | Implique (p,q) -> print_string "("; affiche_formule_aux p;
                        print_string ") -> ("; affiche_formule_aux q; print_string ")"
    | Equivaut (p,q) -> print_string "( ("; affiche_formule_aux p;
                        print_string ") <-> ("; affiche_formule_aux q; print_string ")"
  in
  affiche_formule_aux f;
  print_newline ()


(** Renvoie eval_v(f)
    v est donné comme un tableau de booléen ( i -> v(x_i) )
*)
let rec eval (f : prop) (v : bool array) =
  match f with
  | Const b -> b
  | Var i -> v.(i)
  | Non p -> not (eval p v)
  | Et (p,q) -> eval p v && eval q v
  | Ou (p,q) -> eval p v || eval q v
  | Implique (p,q) -> not (eval p v && not (eval q v))
  | Equivaut (p,q) -> let e_p, e_q = (eval p v, eval q v) in 
                      e_p && e_q || (not e_p && not e_q)


(** Renvoie f[s/x_i] *)
let rec substitue (f : prop) (s : prop) (i : int) =
  match f with
  | Const b -> Const b
  | Var j -> if i = j then s else Var j
  | Non p -> Non (substitue p s i)
  | Et (p,q) -> Et (substitue p s i, substitue q s i)
  | Ou (p,q) -> Ou (substitue p s i, substitue q s i)
  | Implique (p,q) -> Implique (substitue p s i, substitue q s i)
  | Equivaut (p,q) -> Equivaut (substitue p s i, substitue q s i)


(** Renvoie la simplification de Quine de f
*)
let ex2 =
  Implique ( 
    Et (Var 0, Non(Var 1)),
    Et (Var 0, Non (Et (Var 1, Non (Var 2)) ) )
  )

let ex3 = Non ( Et (Const false, Var 0))
let ex4 = Non ( Ou (Var 0, Const false))

let rec simplifie (f : prop) =
  match f with
  | Const b -> Const b
  | Var j -> Var j
  | Non p -> let simpl_p = simplifie p in
              if simpl_p = Const true then Const false
              else if simpl_p = Const false then Const true
              else Non simpl_p
  | Et (p, q) -> let simpl_p = simplifie p in let simpl_q = simplifie q in
              if simpl_p = Const false then Const false
              else if simpl_q = Const false then Const false
              else if simpl_p = Const true then simpl_p
              else if simpl_q = Const false then simpl_q
              else Et (simpl_p, simpl_q)
  | Ou (p, q) -> let simpl_p = simplifie p in let simpl_q = simplifie q in
              if simpl_p = Const true then Const true
              else if simpl_q = Const true then Const true
              else if simpl_p = Const false then simpl_q
              else if simpl_q = Const false then simpl_p
              else Ou (simpl_p, simpl_q)
  | Implique (p, q) -> let simpl_p = simplifie p in let simpl_q = simplifie q in
              if simpl_p = Const true then simpl_q
              else if simpl_q = Const true then Const true
              else if simpl_q = Const false then Non (simpl_p)
              else Implique (simpl_p, simpl_q)
  | Equivaut (p, q) -> let simpl_p = simplifie p in let simpl_q = simplifie q in
              if simpl_p = Const true then simpl_q
              else if simpl_p = Const true && simpl_q = Const true then Const true
              else if simpl_p = Const false && simpl_q = Const false then Const true
              else if simpl_p = Const false then Non (simpl_q)
              else if simpl_q = Const true then simpl_p
              else if simpl_q = Const false then Non (simpl_p)
              else Equivaut (simpl_p, simpl_q)

let ex5 = Implique ( Ou ( Const true, Non ( Var 1 )), Implique ( Const true, Var 1))

let _ = affiche_formule (simplifie ex5)

(* let rec quine (f: prop) (v: int) =
  let simpl_f = simplifie f in
  match simpl_f with
  |  *)