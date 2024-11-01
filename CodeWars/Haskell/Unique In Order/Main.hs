module UniqueInOrder (uniqueInOrder) where



uniqueInOrder :: Eq a => [a] -> [a]
uniqueInOrder [] = []
uniqueInOrder (x: xs)
  | null xs        = [x]
  | x == (head xs) = uniqueInOrder xs
  | otherwise      = x : uniqueInOrder xs
