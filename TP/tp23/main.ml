open List
open Array
open Queue

let g0 = [|
  [1; 6];         (* 0 *)
  [2; 3];         (* 1 *)
  [1; 3; 4; 5];   (* 2 *)
  [2];            (* 3 *)
  [2];            (* 4 *)
  [9; 12];        (* 5 *)
  [7];            (* 6 *)
  [6; 8];         (* 7 *)
  [];             (* 8 *)
  [10];           (* 9 *)
  [11];           (* 10 *)
  [10];           (* 11 *)
  [13];           (* 12 *)
  [12];           (* 13 *)
|]

let g1 = [|
  [1; 6];       (* 0 *)
  [0; 2; 3];    (* 1 *)
  [1; 3; 4; 5]; (* 2 *)
  [1; 2];       (* 3 *)
  [2];          (* 4 *)
  [2; 9; 12];   (* 5 *)
  [0; 7];       (* 6 *)
  [6; 8];       (* 7 *)
  [7];          (* 8 *)
  [5; 10];      (* 9 *)
  [9; 11];      (* 10 *)
  [10];         (* 11 *)
  [5; 13];      (* 12 *)
  [12];         (* 13 *)
|]

let g2 = [|
  [1; 2];       (* 0 *)
  [0; 2];       (* 1 *)
  [0; 1; 3];    (* 2 *)
  [2];          (* 3 *)
  [5];          (* 4 *)
  [4; 6];       (* 5 *)
  [5];          (* 6 *)
  [];           (* 7 *)
  [11; 9];      (* 8 *)
  [8; 10];      (* 9 *)
  [9; 11];      (* 10 *)
  [8; 10];      (* 11 *)
|]

let print_list l =
  let print_aux i = (print_int i; print_char ' ') in
  List.iter print_aux l; print_char '\n'

let _ = print_list g0.(5)

type 'a option = None | Some of 'a

let array_in_index x t =
  let result = ref None in
  for i = 0 to (Array.length t)-1 do
    if x = t.(i) then
      result := Some(i)
  done;
  (* Return *)
  result

let r = array_in_index 2 [|1; 2; 3; 4; 5|]

let print_option o =
  match !o with
  | None -> print_string "None\n"
  | Some(a) -> print_int a; print_char '\n'

let _ = print_option r


type etat = Blanc | Gris | Noir

let bfs_affiche g s =
  let etat = Array.make (Array.length g) Blanc in
  let ajout_voisin t a =
    if etat.(a) <> Noir then
      (Queue.add a t); etat.(a) <- Gris
    
    in

  let q = Queue.create () in
  Queue.add s q;
  while not (Queue.is_empty q) do
    let sommet = Queue.pop q in
    etat.(sommet) <- Noir;
    
    List.iter (ajout_voisin q) g.(sommet);
    print_int sommet; print_char ' '
  done

let _ = bfs_affiche g0 5