



object Solution {
    def longestSubarray(nums: Array[Int]): Int = {
        val m: Int = nums.max
        nums.foldLeft((0, 0, 0)) { case ((left, right, res), num) =>
            if(num == m) {
                (left, right + 1, math.max(res, right + 1 - left))
            } else {
                (right + 1, right + 1, res)
            }
        }._3
    }
}
