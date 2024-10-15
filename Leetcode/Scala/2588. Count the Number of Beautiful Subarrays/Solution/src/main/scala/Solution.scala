



object Solution {
    def beautifulSubarrays(nums: Array[Int]): Long = {
        nums.foldLeft((0L, 0L, scala.collection.mutable.Map[Long,Long](0L -> 1L))) { case ((res, acc, seen), num) =>
            val   xored = acc ^ num
            val  newRes = seen.getOrElse(xored, 0L) + res
            seen(xored) = seen.getOrElse(xored, 0L) + 1L
            (newRes, xored, seen)
        }.head
    }
}
