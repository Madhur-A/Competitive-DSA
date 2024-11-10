



module Main where

import Data.List (groupBy)

main :: IO ()
main = interact $ (solve . map parse . head . tail . lines)

parse :: Char -> Int
parse x
  | x == 'U'  = 1
  | otherwise = negate 1

solve :: [Int] -> String
solve = show . length . filter ( < 0) . map sum . groupBy (\x y -> x /= 0 && y /= 0) . scanl (+) 0
