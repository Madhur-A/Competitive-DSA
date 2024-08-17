



object Solution {
    def minPossibleCountPQ(nums: Array[Int], target: Int): Int = {
        val t = collection.mutable.PriorityQueue[(Int, Int)]()(Ordering.by[(Int, Int), Int](_._2))
        t.enqueue((0, 0))
        val seen = collection.mutable.Set[Int]()
        while (t.nonEmpty) {
            val (sum, count) = t.dequeue()
            if (sum == target) { return count }
            for (num <- nums) {
                if (sum + num <= target && !seen.contains(sum + num)) {
                    t.enqueue((sum + num, count + 1))
                    seen.add(sum + num)
                }
            }
        }
        return -1
    }
    
    def minPossibleCountDP(nums: Array[Int], target: Int): Int = {
        val dp = Array.fill(target + 1)(Int.MaxValue)
        dp(0) = 0
        for (j <- 1 to target) {
            for (num <- nums) {
                if (j >= num && dp(j - num) != Int.MaxValue) {
                    dp(j) = math.min(dp(j), dp(j - num) + 1)
                }
            }
        }
        if (dp(target) == Int.MaxValue) then -1 else dp(target)
    }
    
    def minimumNumbers(num: Int, k: Int): Int = {
        val nums = Array.iterate(k, (num - k) / 10 + 1)(x => x + 10)

        // minPossibleCountDP(nums.toArray, num)
        minPossibleCountPQ(nums.toArray, num)
    }
}
