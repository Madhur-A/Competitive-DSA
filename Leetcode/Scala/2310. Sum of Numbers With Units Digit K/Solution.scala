



import scala.collection.mutable.{PriorityQueue, Map, Queue, Set}

object Solution {
    // all methods given below solve the coin-change problem

    // using Priority Queue
    def minPossibleCountPQ(nums: Array[Int], target: Int): Int = {
        val (t, seen) = (PriorityQueue[(Int, Int)]((0, 0))(Ordering.by[(Int, Int), Int](_._1).reverse), Set[Int]())

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

    // vanilla BFS
    def minPossibleCountBFS(nums: Array[Int], target: Int): Int = {
        val (seen, t) = (Map[Long, Int]((0, 0)), Queue[Long](0))

        while (t.nonEmpty) {
            val popped = t.dequeue()
            nums.foldLeft(((popped == target), seen, t)) { case ((found, seen, t), num) =>
                if (!found) {
                    if (num + popped <= target && !seen.contains(num + popped)) {
                        seen(num + popped) = seen.getOrElse(popped, 0) + 1
                        t.enqueue(num + popped)
                    }
                } 
                (found, seen, t)
            }
        }

        seen.getOrElse(target, -1)
    }


    // the traditional coin-change solution (bottom-up DP)
    def minPossibleCountDP(nums: Array[Int], target: Int): Int = {
        val dp = Array.fill(target + 1)(target + 1)
        dp(0) = 0
        nums.foldLeft(dp) { case (dp, num) =>
            (num to target).foldLeft(dp) { case (dp, j) =>
                dp.update(j, math.min(dp(j), dp(j - num) + 1)); dp
            }
        }.last match {
            case x if x > target => -1
            case x               =>  x
        }
    }

    def minimumNumbers(num: Int, k: Int): Int = {
        val nums = Array.iterate(k, (num - k) / 10 + 1)(x => x + 10)
        
        // minPossibleCountPQ(nums, num)
        // minPossibleCountBFS(nums, num)
        minPossibleCountDP(nums, num)
    }
}
