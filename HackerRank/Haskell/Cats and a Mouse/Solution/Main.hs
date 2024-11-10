



module Main where

main :: IO ()
main = interact $ (unlines . solve . map (map read) . map words . tail. lines)

solve :: [[Int]] -> [String]
solve [] = []
solve ((x : y : z : []) : rest)
  | abs (x - z) < abs (y - z) = "Cat A" : solve rest
  | abs (x - z) > abs (y - z) = "Cat B" : solve rest
  | otherwise                 = "Mouse C" : solve rest
