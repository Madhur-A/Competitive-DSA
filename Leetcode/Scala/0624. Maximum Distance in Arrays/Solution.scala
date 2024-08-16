



object Solution {
    def maxDistance(nums: List[List[Int]]): Int = {
        nums.foldLeft((0, Int.MaxValue/2, Int.MinValue/2)) { case ((res, low, high), num) =>
            (List(res, num.last - low, high - num.head).max, Math.min(low, num.head), Math.max(high, num.last))
        }.head
    }
}

