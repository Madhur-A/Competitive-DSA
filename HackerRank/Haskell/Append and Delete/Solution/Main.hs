-- https://www.hackerrank.com/challenges/append-and-delete/problem
-- i'm not exactly the brighest bulb but even then, despite my efforts
-- i could not deduce the logic of this question

module Main where

main :: IO ()
main = interact $ solve . lines

solve :: [String] -> String
solve (s : t : k : [])
  | s == t               = "Yes"
  | source == []         = if 2 * length target == limit && length target /= 1 then "Yes" else "No"
  | length res <= limit  = "Yes"
  | otherwise            = "No"
  where
    (source, target) = solve' s t
    res              = source ++ target
    limit            = read k :: Int

solve' :: String -> String -> (String, String)
solve' [] [] = ([], [])
solve' s  [] = (s,  [])
solve' []  t = ([],  t)
solve' s t
    | head s == head t  = solve' (tail s) (tail t)
    | otherwise         = (s, t)
