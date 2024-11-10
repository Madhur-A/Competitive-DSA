-- https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem



module Main where

import Data.List (splitAt)

main :: IO ()
main = interact $ show . solve . map (map read) . map words . lines

solve :: [[Int]] -> Int
solve ((n : k : []) : nums : []) =
  let landing = if head nums == 1 then 3 else 1
  in (-) 100 $ solve' landing k $ swapped k ((-1) : tail nums)

solve' :: Int -> Int -> [Int] -> Int
solve' landing k (first : rest)
  | negate 1 == first  = landing
  | otherwise          = (if first == 1 then 3 else 1) + solve' landing k (swapped k (first : rest))

swapped :: Int -> [Int] -> [Int]
swapped k nums =
  let (prefix, suffix) = splitAt k nums
  in suffix ++ prefix
