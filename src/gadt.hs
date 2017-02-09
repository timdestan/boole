{-# LANGUAGE GADTs #-}

data Exp a where
  I :: Int -> Exp Int
  B :: Bool -> Exp Bool
  Add :: Exp Int -> Exp Int -> Exp Int
  Eq :: Exp Int -> Exp Int -> Exp Bool

instance Show (Exp a) where
  show (I i) = show i
  show (B b) = show b
  show (Add x y) = "(" ++ show x ++ " + " ++ show y ++ ")"
  show (Eq x y) = show x ++ " = " ++ show y

eval :: Exp a -> a
eval (I i) = i
eval (B b) = b
eval (Add x y) = eval x + eval y
eval (Eq x y) = eval x == eval y

showResult :: Show a => Exp a -> IO ()
showResult a = putStrLn $ show a ++ " -> " ++ show (eval a)

main = do
  showResult (Eq (Add (I 4) (I 3)) (I 7))
  showResult (Eq (I 4) (I 3))
