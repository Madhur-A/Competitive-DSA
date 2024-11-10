-- https://open.kattis.com/problems/downtime
-- priority queue emulation via binary insertion


module Main where

import qualified Data.Sequence as DS

main :: IO ()
main = interact $ (show . solve . map (map read) . map words . lines)

solve :: [[Int]] -> Int
solve ((n : k : []) : rest) = solve' k k DS.empty $ concat rest

solve' :: Int -> Int -> DS.Seq Int -> [Int] -> Int
solve' m n t [] = 1
solve' m n t (curr : rest)
  | length updated >= m = 1 + solve' (n + m) n added rest
  | otherwise           = 0 + solve' m n added rest
  where
    updated = DS.dropWhileL ( <= curr) t
    added   = DS.insertAt (findRight updated (curr + 1000)) (curr + 1000) updated

findRight :: DS.Seq Int -> Int -> Int
findRight nums target = rx left right
  where left  = 0
        right = length nums
        rx l r
          | r <= l                    = l
          | DS.index nums m > target  = rx l m
          | otherwise                 = rx (m + 1) r
          where
            m = div (l + r) 2
