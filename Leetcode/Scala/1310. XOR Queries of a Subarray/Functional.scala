







object Functional {
    def xorQueries(nums: Array[Int], queries: Array[Array[Int]]): Array[Int] = {
        queries.foldLeft((List[Int](), nums.scanLeft(0)(_ ^ _))) { case ((res, pfx), indices) =>
            (res ++ List(pfx(indices.head) ^ pfx(indices.last + 1)), pfx)
        }.head.toArray
    }
}

