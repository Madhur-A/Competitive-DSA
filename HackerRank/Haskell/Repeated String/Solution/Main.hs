



module Main where

main :: IO ()
main  = interact $ solve . lines

solve :: [String] -> String
solve (s : num : []) =
  let ((n, k), a) = (divMod (read num :: Int) (length s), (length . filter (=='a')) s)
  in show $ (n * a) + (length . filter (=='a') . take k) s
