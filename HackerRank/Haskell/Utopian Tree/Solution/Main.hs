



module Main where

main :: IO ()
main = interact $ unlines . map show . solve . map read . tail . lines

solve :: [Int] -> [Int]
solve nums = [solve' num | num <- nums]

solve' :: Int -> Int
solve' 0 = 1
solve' n
  | odd n     = 2 * solve' (pred n)
  | otherwise = 1 + solve' (pred n)
