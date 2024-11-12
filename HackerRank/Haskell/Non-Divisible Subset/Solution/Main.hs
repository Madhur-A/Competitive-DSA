



module Main where

import Data.List (splitAt)

main :: IO ()
main = interact $ show . solve . map (map read) . map words . lines

freqs :: Int -> [Int] -> [Int] -> [Int]
freqs _ f     [] = f
freqs k f (first : rest) =
  let (prefix, suffix) = splitAt (mod first k) f
  in freqs k (prefix ++ [succ (head suffix)] ++ tail suffix) rest

solve :: [[Int]] -> Int
solve (( _ : k : []) : nums : [])  =
  let f = freqs k (take (k + 1) $ repeat 0) nums
  in foldl (\res i -> if (i == k - i) then (res + 1) else res + (max (f !! (k - i)) (f !! i))) (min 1 (f !! 0)) [1 .. (div k 2)]
