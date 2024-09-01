



object Solution {
    def lengthOfLIS(nums: Array[Int]): Int = {
        nums.indices.drop(1).foldLeft(Array.fill(nums.length)(1)) { case (dp, index) =>
            var innerMax = 0
            dp.take(index).indices.foreach { j =>
                if (nums(j) < nums(index)) {
                    innerMax = Math.max(innerMax, dp(j) + 1)
                }
            }
            dp.update(index, Math.max(dp(index), innerMax)); dp
        }.max        
    }
}
