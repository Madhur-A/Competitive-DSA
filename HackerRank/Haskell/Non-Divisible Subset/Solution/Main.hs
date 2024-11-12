



module Main where

import Data.List (splitAt)

main :: IO ()
main = interact $ show . solve . map (map read) . map words . lines

insert :: [Int] -> Int -> [Int]
insert nums index =
  let (prefix, suffix) = splitAt index nums
  in prefix ++ [succ (head suffix)] ++ tail suffix

freqs :: Int -> [Int] -> [Int] -> [Int]
freqs _ f             [] = f
freqs k f (first : rest) = freqs k (insert f (rem first k)) rest

solve :: [[Int]] -> Int
solve (( _ : k : []) : nums : [])  =
  let f = freqs k (take (k + 1) $ repeat 0) nums
  in foldl (\res i -> if (i == k - i) then (res + 1) else res + (max (f !! (k - i)) (f !! i))) (min 1 (f !! 0)) [1 .. (div k 2)]
