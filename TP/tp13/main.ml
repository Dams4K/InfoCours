let rec separe l = match l with
| [] -> ( [] , [] )
| [h] -> ( [h] , [] )
| h0 :: h1 :: t -> let (g,d) = separe t in (h0::g, h1::d)


let rec fusion l0 l1 = match (l0, l1) with
| ([], []) -> []
| (_, h0::t0) -> l1
| (h0::t0, _) -> l0
| (h0::t0), (h1::t1) when h0 <= h1 -> h0::h1::(fusion t0 t1)
| (h0::t0), (h1::t1) when h0 >  h1 -> h1::h0::(fusion t0 t1)

let rec tri_fusion l = match l with
| [] -> []
| [h] -> [h]
| _ -> let (g, d) = separe l in fusion (tri_fusion g) (tri_fusion d)