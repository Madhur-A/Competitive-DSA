







object Solution {
    def xorQueries(nums: Array[Int], queries: Array[Array[Int]]): Array[Int] = {
        queries.foldLeft((List[Int](), nums.scanLeft(0)(_ ^ _))) { case ((res, pfx), index) =>
            (res ++ List(pfx(index.head) ^ pfx(index.last + 1)), pfx)
        }.head.toArray
    }
}

