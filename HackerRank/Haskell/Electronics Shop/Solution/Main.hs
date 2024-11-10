



module Main where

import Data.List (maximum)

main :: IO ()
main = interact $ (solve . map (map read) . map words . lines)

solve :: [[Int]] -> String
solve ((b : _) : k : m : _)
  | afford == []  = "-1"
  | otherwise     = show $ maximum $ afford
  where afford = filter (<= b) [x + y | x <- k, y <- m]
