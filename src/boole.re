type relop =
  | Lt
  | Le
  | Gt
  | Ge
  | Eq
  | Ne;

let eval_relop op x y =>
  switch op {
  | Lt => x < y
  | Le => x <= y
  | Gt => x > y
  | Ge => x >= y
  | Eq => x == y
  | Ne => x != y
  };

type exp =
  | Not exp
  | And (list exp)
  | Or (list exp)
  | RelOp relop int int;

let id a => a;

module Monoid = {
  type t 'a = {zero: 'a, combine: 'a => 'a => 'a};
  let m_and = {zero: true, combine: (&&)};
  let m_or = {zero: false, combine: (||)};
  let rec reduce m =>
    fun
    | [] => m.zero
    | [x, ...xs] => m.combine x (reduce m xs);
};

let rec eval (e: exp) :bool =>
  switch e {
  | Not e => not (eval e)
  | And es => Monoid.reduce Monoid.m_and (List.map eval es)
  | Or es => Monoid.reduce Monoid.m_or (List.map eval es)
  | RelOp op v1 v2 => eval_relop op v1 v2
  };

let pp_relop op =>
  switch op {
  | Lt => "<"
  | Le => "<="
  | Gt => ">"
  | Ge => ">="
  | Eq => "=="
  | Ne => "!="
  };

let in_parens s => "(" ^ s ^ ")";

let rec pp (e: exp) :string =>
  switch e {
  | Not e => in_parens ("~" ^ pp e)
  | And es => in_parens (String.concat " ^ " (List.map pp es))
  | Or es => in_parens (String.concat " V " (List.map pp es))
  | RelOp op e1 e2 => in_parens (string_of_int e1 ^ " " ^ pp_relop op ^ " " ^ string_of_int e2)
  };

print_endline @@ pp (Not (And [RelOp Lt 3 4, RelOp Ne 4 5]));
