type exp _ =
  | I int :exp int
  | B bool :exp bool
  | Add (exp int) (exp int) :exp int
  | Eq (exp int) (exp int) :exp bool;

let rec show: type a. exp a => string =
  fun
  | I i => string_of_int i
  | B b => string_of_bool b
  | Add x y => "(" ^ show x ^ " + " ^ show y ^ ")"
  | Eq x y => show x ^ " = " ^ show y;

let rec eval: type a. exp a => a =
  fun
  | I i => i
  | B b => b
  | Add x y => eval x + eval y
  | Eq x y => eval x == eval y;

let showBoolResult (e: exp bool) :unit =>
  print_endline @@ show e ^ " -> " ^ string_of_bool @@ eval e;

showBoolResult (Eq (Add (I 4) (I 3)) (I 7));

showBoolResult (Eq (I 4) (I 3));
