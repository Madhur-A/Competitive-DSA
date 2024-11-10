



module Main where

main :: IO ()
main = interact $ (show . needed . map read . lines)

needed :: [Int] -> Int
needed (n : k : []) =
    let turns = div k 2
    in min turns $ (div n 2) - turns
