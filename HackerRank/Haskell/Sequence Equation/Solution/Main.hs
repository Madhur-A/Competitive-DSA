-- https://www.hackerrank.com/challenges/permutation-equation/problem



import qualified Data.Map as DMap

main :: IO ()
main = interact $ (solve . map (map read) . map words . lines)

solve :: [[Int]] -> String
solve ((n : []) : nums : []) =
  let g = DMap.fromList $ zip nums ([1 .. length nums])
  in unlines $ map show [g DMap.! (g DMap.! index) | index <- [1 .. n]]
