



object Solution {
    def jump(nums: Array[Int]): Int = {
        nums.indices.dropRight(1).foldLeft((0, 0, 0, 0)) { case ((res, maxSoFar, maxIndex, index), i) =>
            val newMaxSoFar = Math.max(maxSoFar, i + nums(i))
            (i == index) match {
                case  true => (res + 1, newMaxSoFar, newMaxSoFar, newMaxSoFar)
                case false => (res, newMaxSoFar, maxIndex, index)
            }
        }.head
    }
}
