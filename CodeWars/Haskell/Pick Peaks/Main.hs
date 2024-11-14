-- module PickPeak.JorgeVS.Kata where



-- zero imports solution

data PickedPeaks = PickedPeaks { pos :: [Int], peaks :: [Int]} deriving (Eq, Show)
                      --index value
peakFilter :: (Int, Int) -> [(Int, Int)] -> [(Int, Int)]
peakFilter _ [] = []
peakFilter (previousIndex, previousValue) ((index, first) : rest) =
  if (first /= previousValue) then ((previousIndex, previousValue) : (peakFilter (index, first) rest)) else peakFilter (index, first) rest

         -- index value
mountain :: [(Int, Int)]-> [(Int, (Int, Int, Int))]
mountain given =
  let p = map snd given; q = tail p; r = tail q
  in zip (map fst given) (zip3 p q r)

getPeaks :: [(Int, (Int, Int, Int))] -> PickedPeaks -> PickedPeaks
getPeaks [] res = res
getPeaks ((i, (x, y, z)) : rest) res
  | (x < y) && (y >= z) = getPeaks rest $ PickedPeaks { pos = (pos res) ++ [i + 1], peaks = (peaks res) ++ [y] }
  | otherwise           = getPeaks rest res

zipped :: [Int] -> [(Int, Int)]
zipped peaks = zip [0 .. (pred $ length peaks)] peaks

pickPeaks :: [Int] -> PickedPeaks
pickPeaks p =
  let pi = zipped (p ++ [1000000000000]); pz = peakFilter (head pi) pi
  in getPeaks (mountain pz) PickedPeaks { pos = [], peaks = [] }
