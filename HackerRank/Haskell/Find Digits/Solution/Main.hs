



module Main where

main :: IO ()
main = interact $ solve . map read . tail . lines

solve :: [Int] -> String
solve nums = unlines $ map show [solve' num num | num <- nums]

solve' :: Int -> Int -> Int
solve' num curr
  | curr == 0                            = 0
  | divisor /= 0 && rem num divisor == 0 = 1 + solve' num divided
  | otherwise                            = solve' num divided
  where
    divisor = rem curr 10
    divided = div curr 10
