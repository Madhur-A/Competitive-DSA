



module Main where

main :: IO ()
main = interact $ unlines . map show . map solve . map read . tail . lines


solve :: Int -> Int
solve num
  | diff < 3 && num > 40 = (num + diff)
  | otherwise            = num
  where diff = (mux * 5) - num
        mux  = div (num + 4) 5
