



module Main where

main :: IO ()
main = interact $ unlines . map show . solve . map (map read) . map words . tail . lines

solve :: [[Int]] -> [Int]
solve [] = []
solve (first: second: rest) =
  let
    (b: w: bc: wc: z: []) = concat (first : second: [])
    minBlack              = min bc (wc + z)
    minWhite              = min wc (bc + z)
  in
    (b * minBlack + w * minWhite) : solve rest
