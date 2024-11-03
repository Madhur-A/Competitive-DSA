-- "Ooarai Joshigakuin Shori!"



module Main where

import Data.List
import Text.Read

main :: IO ()
main = interact $ unlines . map solve . groupByDelimiter

groupByDelimiter :: String -> [[String]]
groupByDelimiter inputString =
    let linesInput = tail . lines $ inputString
        groupDelimited [] = []
        groupDelimited xs =
            let (n:prefix) = xs
                (rows, suffix) = splitAt (read n :: Int) prefix
            in rows : groupDelimited suffix
    in groupDelimited linesInput

solve :: [String] -> String
solve input | and $ map isSorted . transpose . map sort $ input = "YES"
            | otherwise                                         = "NO"

isSorted :: Ord a => [a] -> Bool
isSorted [] = True
isSorted (first : []) = True
isSorted (first : rest) = first <= (head rest) && isSorted rest
