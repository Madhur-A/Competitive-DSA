



object Solution {
    def countFairPairs(nums: Array[Int], lower: Int, upper: Int): Long = {
        val n = nums.length
        val sortedNums = nums.sorted

        def findRight(left: Int, right: Int, target: Int): Int = (left < right) match {
            case  true => {
                val mid = left + ((right - left) >> 1)
                sortedNums(mid) >= target match {
                    case  true => findRight(left, mid, target)
                    case false => findRight(mid + 1, right, target)
                }
            }
            case false => left
        }

        sortedNums.zipWithIndex.foldLeft(0L) { case (res, (num, left)) =>
            val hi = findRight(left + 1, n, upper - num + 1)
            val lo = findRight(left + 1, n, lower - num);
            res + (hi - lo)
        }
    }
}
