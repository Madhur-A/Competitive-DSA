



module Main where

main :: IO ()
main = interact $ show . solve . map (map read . words) . tail. lines

solve :: [[Int]] -> Int
solve (firstArray : (first :  rest) : _) =
      let left  = foldl lcm 1 firstArray
          right = foldl gcd first rest
      in length $ filter (\x -> mod right x == 0) $ takeWhile ( <= right) $ iterate (+left) left
