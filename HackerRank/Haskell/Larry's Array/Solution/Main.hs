



module Main where

main :: IO ()
main = interact $ solve

inversions :: [Int] -> Int
inversions xs = sum [1 | (x, y) <- pairs xs, x > y]
  where
    pairs :: [a] -> [(a, a)]
    pairs xs = [(x, y) | (x, i) <- zip xs [0..], (y, j) <- zip xs [0..], i < j]

sortable :: [Int] -> String
sortable xs = if even (inversions xs) then "YES" else "NO"

solve :: String -> String
solve t = unlines $ map sortable $ map (map read) $ map words $ [x | (x, i) <- zip (tail $ lines t) [1..], even i]
