



// certainly NOT functional
object Solution {
    val inf: Long = Int.MinValue

    def maxScore(nums: Array[Int], k: Int): Long = {
        val res = if ((nums.head & 1) == 1) Array(inf, nums.head.toLong) else Array(nums.head.toLong, inf)
        nums.tail.foldLeft(res) { case (res, num) =>
            val (i, j) = ((num & 1), (num & 1) ^ 1)
            val (a, b) = (math.max(res(i) + num, res(j) + num - k), math.max(res(j), res(i) + num - k))
            res(i) = a; res(j) = b; res
        }.max
    }
}
