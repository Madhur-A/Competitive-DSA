



object Solution {
    def minSubarray(nums: Array[Int], p: Int): Int = {
        val totalSum = nums.map(_.toLong).sum % p
        if (totalSum != 0) {
            val prefixMap = scala.collection.mutable.Map[Long, Int](0L -> -1)
            var (res, total) = (Int.MaxValue, 0L)

            for (i <- nums.indices) {
                total = (total + nums(i)) % p
                val newKey = (total - totalSum + p) % p
                prefixMap(total) = i
                res = math.min(res, math.abs(i - prefixMap.getOrElse(newKey, Int.MaxValue)))
            }
            if (res == nums.length || res == Int.MaxValue) -1 else res

        } else 0
    }
}
