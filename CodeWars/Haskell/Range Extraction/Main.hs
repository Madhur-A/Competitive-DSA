module RangeExtractor.JorgeVS.Kata where



import Data.List (groupBy, intercalate)

solution :: [Integer] -> String
solution = intercalate "," . map formatRange . foldr groupRanges []
  where
    groupRanges first res | res == []               = [[first]]
                          | succ first == head curr = (first : curr) : rest
                          | otherwise               = [first]: res
      where (curr : rest) = res

    formatRange xs | length xs < 3 = intercalate "," $ map show xs
                   | otherwise     = show (head xs) ++ "-" ++ show (last xs)
