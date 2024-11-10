-- https://open.kattis.com/problems/baloni



module Main where

import qualified Data.Map.Strict as M

main :: IO ()
main = interact $ (show . solve M.empty . map read . words . head . tail . lines)

contains :: M.Map Int Int -> Int -> Int
contains g key =
  case M.lookup key g of
    Nothing -> 0
    Just x  -> x

solve :: M.Map Int Int -> [Int] -> Int
solve _ [] = 0
solve seen (curr : rest)
  | found > 0          = solve (M.insert curr (pred found) updatedSeen) rest
  | otherwise          = 1 + solve updatedSeen rest
  where
    found       = contains seen curr
    updatedSeen = M.insert (pred curr) (succ $ contains seen $ pred curr) seen
