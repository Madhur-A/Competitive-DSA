



object Solution {
    def countMaxOrSubsets(nums: Array[Int]): Int = {
        val n = nums.length
        val u = 1 << n
        val maxOr = nums.scanLeft(0)(_ | _).max
        (0 until u).foldLeft(0) { case (res, index) =>
            (0 until n).foldLeft(0) { case (orred, j) =>
                ((1 << j) & index) match {
                    case 0 => orred
                    case _ => orred | nums(j)
                }
            } match {
                case x if x == maxOr => res + 1
                case x               => res
            }
        }
    }
}
