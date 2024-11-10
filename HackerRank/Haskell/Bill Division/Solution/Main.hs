



main :: IO ()
main = interact $ solve . map (map read) . map words . lines

solve :: [[Int]] -> String
solve ((n : k : []) : bill : (charged : []) : []) =
  let actual = div (sum bill - bill !! k) 2
  in if actual == charged then "Bon Appetit" else show (charged - actual)
