



object Solution {
    def maxProduct(nums: Array[Int]): Int = {
        val (n, dp) = (nums.length, Array.ofDim[Long](nums.length, 2))
        dp(0)(0) = nums(0).toLong
        dp(0)(1) = nums(0).toLong

        (1 until n).foreach { index =>
            val maxValue = math.max(nums(index), dp(index-1)(1) * nums(index).toLong)
            val minValue = math.min(nums(index), dp(index-1)(1) * nums(index).toLong)
            dp(index)(0) = math.max(dp(index-1)(0) * nums(index).toLong, math.min(Int.MaxValue, maxValue))
            dp(index)(1) = math.min(dp(index-1)(0) * nums(index).toLong, math.max(Int.MinValue, minValue))
        }

        dp.map(_(0)).max.toInt

    }
}
