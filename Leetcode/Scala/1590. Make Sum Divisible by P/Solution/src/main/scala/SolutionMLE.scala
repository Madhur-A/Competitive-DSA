



object SolutionMLE {
    def minSubarray(nums: Array[Int], p: Int): Int = nums.map(_.toLong).sum % p match {
        case 0 => 0
        case _ => {
            nums.foldLeft(Int.MaxValue, 0, 0L, Map(0L -> -1)) { case ((res, index, total, prefixMap), num) =>
                val newSum = (num + total) % p
                val newKey = (newSum - (nums.map(_.toLong).sum % p) + p) % p
                (math.min(res, math.abs(index - prefixMap.getOrElse(newKey, Int.MaxValue))), index + 1, newSum, prefixMap + (newSum -> index))
            }.head match {
                case x if (x == nums.length || x == Int.MaxValue) => -1
                case x                                            =>  x
            }
        }
    }
}
