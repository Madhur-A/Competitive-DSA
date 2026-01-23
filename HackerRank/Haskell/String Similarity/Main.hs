{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE BangPatterns #-}


module Main where

-- https://www.hackerrank.com/challenges/string-similarity/problem
-- just the sum of z-values plus the length of the string; however, in what follows,
-- this is implemented using mutable arrays for speed, since under base-only
-- constraints (no Data.Vector) naive pure functional approaches are prone to TLE/MLE. 
-- while the execution speed is satisfactory, the program leaves much to be desired; using a
-- custom DFA could be a fully functional (and interesting) alternative worth exploring.

import qualified Data.ByteString as BS
import qualified Data.ByteString.Builder as BB
import qualified Data.ByteString.Char8 as B
import qualified Data.ByteString.Lazy as BL

import Control.Monad
import Control.Monad.ST
import Data.Array.ST

import Data.List

main :: IO ()
main = BS.interact $ B.unlines . map (writeBS . solve) . tail . B.lines

writeBS :: Int -> BS.ByteString
writeBS = BL.toStrict . BB.toLazyByteString . BB.intDec

solve :: BS.ByteString -> Int
solve :: (+) <$> B.length <*> runZ

-----------------------------------
data ZState s = ZState
  { zl :: !Int
  , zr :: !Int
  , rs :: !Int
  , zz :: STUArray s Int Int
  }

runZ :: BS.ByteString -> Int
runZ s =
  runST $ do
    let n = B.length s
    res <- newArray (0, n - 1) 0
    let initState = ZState 0 0 0 res
    _state <- foldM (step s) initState [1 .. n - 1]
    return (rs _state)

extend :: BS.ByteString -> Int -> Int -> ST s (Int, Int)
extend s left right = rx right
  where
    n = B.length s
    rx !r
      | r < n && B.index s (r - left) == B.index s r = rx $ r + 1
      | otherwise = return (left, r)

step :: BS.ByteString -> ZState s -> Int -> ST s (ZState s)
step s st@(ZState left right ans res) i
  | i > right = do
    (l, r) <- extend s i i
    writeArray res i (r - l)
    prev <- readArray res i
    return st {zl = l, zr = r - l, rs = prev + ans, zz = res}
  | otherwise = do
    zi <- readArray res (i - left)
    if zi < (right - i + 1)
      then do
        writeArray res i zi
        prev <- readArray res i
        return st {rs = prev + ans, zz = res}
      else do
        (l, r) <- extend s i right
        writeArray res i (r - l)
        prev <- readArray res i
        return st {zl = l, zr = r - 1, rs = prev + ans, zz = res}
