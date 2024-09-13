







object Solution {
    def xorQueries(nums: Array[Int], queries: Array[Array[Int]]): Array[Int] = {
        val (res, prefixXors) = (Array.fill(queries.length)(0), nums.scanLeft(0)(_ ^ _))
        queries.foldLeft((res, 0)) { case ((res, i), indices) =>
            res.update(i, prefixXors(indices.head) ^ prefixXors(indices.last + 1)); (res, i + 1)
        }.head
    }
}

