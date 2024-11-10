-- https://open.kattis.com/problems/downtime
-- priority queue emulation via binary insertion


module Main where

import qualified Data.Sequence as DS

main :: IO ()
main = interact $ (show . solve . map (map read) . map words . lines)

findRight :: DS.Seq Int -> Int -> Int
findRight nums target =
  let
    l = 0
    r = length nums
  in
    rx l r
  where
    rx left right
      | right <= left               = left
      | DS.index nums mid > target  = rx left mid
      | otherwise                   = rx (mid + 1) right
      where
        mid = div (left + right) 2

solve :: [[Int]] -> Int
solve ((n : k : []) : rest) = solve' k k (DS.fromList []) $ concat rest

solve' :: Int -> Int -> DS.Seq Int -> [Int] -> Int
solve' m n t [] = 1
solve' m n t (curr : rest)
  | length updated >= m = 1 + solve' (n + m) n added rest
  | otherwise           = 0 + solve' m n added rest
  where
    updated = DS.dropWhileL ( <= curr) t
    added   = DS.insertAt (findRight updated (curr + 1000)) (curr + 1000) updated
