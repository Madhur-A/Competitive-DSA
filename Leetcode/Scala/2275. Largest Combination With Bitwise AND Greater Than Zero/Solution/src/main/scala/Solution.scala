



object Solution {
    def largestCombination(candidates: Array[Int]): Int = {
        (0 to 31).foldLeft(0) { case (maxCount, bitPosition) =>
            val mask = 1 << bitPosition
            val count = candidates.foldLeft(0) { case (res, num) =>
                (num & mask) match {
                    case 0 => res
                    case _ => res + 1
                }
            }
            math.max(maxCount, count)
        }
    }
}
