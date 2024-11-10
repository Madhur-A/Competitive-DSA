-- https://www.hackerrank.com/challenges/circular-array-rotation/problem



module Main where

import Data.List (splitAt)

main :: IO ()
main = interact $ (solve . map (map read) . map words . lines)

solve :: [[Int]] -> String
solve ((n : k : q : []) : nums : rest) =
  let rotated = reverse $ rotate (rem k n) (reverse nums)
  in unlines $ map show $ [(!!) rotated index | index <- concat rest]

rotate :: Int -> [Int] -> [Int]
rotate index nums =
  let (prefix, suffix) = splitAt index nums
  in suffix ++ prefix
