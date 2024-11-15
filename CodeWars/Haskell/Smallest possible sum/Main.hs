-- module Kata.SmallestPossibleSum where



import Data.List (sum, sort)

smallestPossibleSum :: (Integral a) => [a] -> a
smallestPossibleSum [] = 0
smallestPossibleSum (0 : rest) = smallestPossibleSum rest
smallestPossibleSum nums@(first : rest)
  | all (== first) nums = sum nums
  | otherwise           = smallestPossibleSum $ sort $ map (\e -> (($*) e first)) $ nums
  where ($*) num 0 = num
        ($*) num divisor | remainder == 0 = divisor
                         | otherwise      = remainder
                         where remainder = rem num divisor
