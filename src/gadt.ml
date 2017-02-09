
type _ exp =
  | I : int -> int exp
  | B : bool -> bool exp
  | Add : int exp * int exp -> int exp
  | Eq : int exp * int exp -> bool exp

let rec show: type a. a exp -> string =
  function
  | I i -> string_of_int i
  | B b -> string_of_bool b
  | Add (x, y) -> ("(" ^ show x ^ " + " ^ show y ^ ")")
  | Eq (x, y) -> (show x ^ " = " ^ show y)

let rec eval: type a . a exp -> a =
  function
  | I i -> i
  | B b -> b
  | Add (x, y) -> (eval x) + (eval y)
  | Eq (x, y) -> ((eval x) = (eval y))

;;

let showBoolResult (e: bool exp):unit =
  print_endline @@ show e ^ " -> " ^ (string_of_bool @@ eval e)

;;

showBoolResult (Eq (Add (I 4, I 3), I 7));;
showBoolResult (Eq (I 4, I 3));;
