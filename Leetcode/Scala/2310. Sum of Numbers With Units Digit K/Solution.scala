



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

    // the aka traditional coin-change problem
    def minPossibleCountDP(nums: Array[Int], target: Int): Int = {
        val dp = Array.fill(target + 1)(target + 1)
        dp(0) = 0
        nums.foldLeft(dp) { case (dp, num) =>
            (num to target).foldLeft(dp) { case (dp, j) =>
                dp.update(j, math.min(dp(j), dp(j - num) + 1)); dp
            }
        }.last match {
            case x if x > target => -1
            case x => x
        }
    }
    
    def minimumNumbers(num: Int, k: Int): Int = {
        val nums = Array.iterate(k, (num - k) / 10 + 1)(x => x + 10)

        minPossibleCountDP(nums.toArray, num)
        // minPossibleCountPQ(nums.toArray, num)
    }
}
