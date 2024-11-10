-- https://open.kattis.com/problems/jollyjumpers




module Main where

import Data.List (sort)

main :: IO ()
main = interact $ (concatMap valid . map (map read) . map tail . map words . lines)

valid :: [Int] -> String
valid nums
  | diff == indices = "Jolly\n"
  | otherwise       = "Not jolly\n"
  where
    diff    = sort $ map abs $ zipWith (-) nums (tail nums)
    indices = [1 .. pred $ length nums]
