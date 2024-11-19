module Codewars.Kata.ModSys (fromNb2Str) where



fromNb2Str :: Integer -> [Integer] -> String
fromNb2Str n xs
  | p < n || l /= p = "Not applicable"
  | otherwise       = concatMap (\x -> "-" ++ (show $ rem n x) ++ "-") xs
  where p = product xs :: Integer; l = foldl lcm 1 xs :: Integer
