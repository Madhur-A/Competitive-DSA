



object Solution {
    def lengthOfLIS(nums: Array[Int]): Int = {
        nums.indices.drop(1).foldLeft(Array.fill(nums.length)(1)) { case (dp, index) =>
            dp.update(index, Math.max(dp(index), {
                dp.take(index).indices.foldLeft(0) { case (innerMax, j) =>
                    if (nums(index) <= nums(j)) innerMax else {
                        Math.max(innerMax, dp(j) + 1)
                    }
                }
            })); dp
        }.max
    }
}
