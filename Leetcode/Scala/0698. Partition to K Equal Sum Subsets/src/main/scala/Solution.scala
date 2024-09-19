



object Solution {
    def canPartitionKSubsets(nums: Array[Int], k: Int): Boolean = {
        nums.sum match {
            case x if ((x % k) != 0) => false
            case x                   => {
                val n = nums.length;
                val (visited, target) = (Array.fill(1 << n)(-1), x / k)
                visited.update(0, 0)
                visited.indices.foldLeft(false) { case (res, i) =>
                    if (visited(i) != -1) {
                        nums.indices.foreach { j =>
                            if ((i & (1 << j)) == 0 && visited(i) + nums(j) <= target) {
                                visited.update(i | (1 << j), (visited(i) + nums(j)) % target)
                            }
                        }
                    }; visited.last == 0
                }
            }
        }
    }
}
