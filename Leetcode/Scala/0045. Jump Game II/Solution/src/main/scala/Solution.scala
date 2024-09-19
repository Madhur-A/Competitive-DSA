



object Solution {
    def jump(nums: Array[Int]): Int = {
        nums.indices.dropRight(1).foldLeft((0, 0, 0, 0)) { case ((res, maxSoFar, maxIndex, index), i) =>
            val newMaxSoFar = Math.max(maxSoFar, i + nums(i))
            if (i == index) {
                (res + 1, newMaxSoFar, newMaxSoFar, newMaxSoFar)
            } else {
                (res, newMaxSoFar, maxIndex, index)
            }
        }.head
    }
}

