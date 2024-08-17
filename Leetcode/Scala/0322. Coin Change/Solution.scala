



import scala.collection.mutable.{PriorityQueue, Map, Queue, Set}

object Solution {
    // all methods given below solve the coin-change problem

    // using Priority Queue
    def minPossibleCountPQ(coins: Array[Int], target: Int): Int = {        
        val (seen, t) = (Set[Long](0L), PriorityQueue[(Long, Int)]((0L, 0))(Ordering.by[(Long, Int), Long](_._2).reverse))
        
        while (t.nonEmpty) {
            val (sum, count) = t.dequeue()
            if (sum == target) { return count }
            for (coin <- coins) {
                if (sum + coin <= target && !seen.contains(sum + coin)) {
                    t.enqueue((sum + coin, count + 1))
                    seen.add(sum + coin)
                }
            }
        }

        return -1
    }

    // vanilla BFS
    def minPossibleCountBFS(coins: Array[Int], target: Int): Int = {
        val (seen, t) = (Map[Long, Int]((0L, 0)), Queue[Long](0L))

        while (t.nonEmpty) {
            val popped = t.dequeue()
            coins.foldLeft(((popped == target), seen, t)) { case ((found, seen, t), coin) =>
                if (!found) {
                    if (coin + popped <= target && !seen.contains(coin + popped)) {
                        seen(coin + popped) = seen.getOrElse(popped, 0) + 1
                        t.enqueue(coin + popped)
                    }
                } 
                (found, seen, t)
            }
        }

        seen.getOrElse(target, -1)
    }


    // the traditional coin-change solution (bottom-up DP)
    def minPossibleCountDP(coins: Array[Int], target: Int): Int = {
        val dp = Array.fill(target + 1)(target + 1)
        dp(0) = 0
        coins.foldLeft(dp) { case (dp, coin) =>
            (coin to target).foldLeft(dp) { case (dp, j) =>
                dp.update(j, math.min(dp(j), dp(j - coin) + 1)); dp
            }
        }.last match {
            case x if x > target => -1
            case x               =>  x
        }
    }

    def coinChange(coins: Array[Int], amount: Int): Int = {
        // minPossibleCountPQ(coins, amount)
        // minPossibleCountBFS(coins, amount)
        minPossibleCountDP(coins, amount)
    }
}

