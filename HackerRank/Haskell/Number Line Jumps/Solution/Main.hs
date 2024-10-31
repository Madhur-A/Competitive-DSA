-- https://www.hackerrank.com/challenges/kangaroo/problem



module Main where

main :: IO()
main = interact $ (f . map read . words)

f :: [Int] -> String
f [a, u, b, v]
  | v < u && (eval == 0) = "YES"
  | otherwise            = "NO"
  where eval = mod (b - a) (u - v)
