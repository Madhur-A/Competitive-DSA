



module Main where

import Data.List (group, sort)

main :: IO ()
main  = interact $ show . solve . map read . words . head . tail . lines

solve :: [Int] -> Int
solve = sum . map (flip div 2) . map length . group . sort
