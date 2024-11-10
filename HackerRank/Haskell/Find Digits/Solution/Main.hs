-- https://www.hackerrank.com/challenges/find-digits/problem



module Main where

import Data.Char (digitToInt)

main :: IO ()
main = interact $ solve . map read . tail . lines

solve :: [Int] -> String
solve nums = unlines $ map show [solve' num | num <- nums]

solve' :: Int -> Int
solve' num = length $ filter (\x -> ((x /= 0) && (0 == rem num x))) $ map digitToInt $ show num
