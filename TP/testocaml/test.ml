type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let tree_calc = Mod( Mul( Add(Var("x"), Int(1)), Add(Var("x"), Int(-1)) ), Int(3))