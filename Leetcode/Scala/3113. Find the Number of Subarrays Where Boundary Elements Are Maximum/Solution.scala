



object Solution {
    def numberOfSubarrays(nums: Array[Int]): Long = {
        nums.foldLeft((0L, List.empty[(Int, Int)])) {
            case((ans, stack), num) => {
                val u = stack.dropWhile(_._1 < num)
                val v = if(u.isEmpty || u.head._1 != num) { (num, 0) :: u } else u
                val w = (num, v.head._2 + 1) :: v.tail
                (ans + w.head._2, w)
            }
        }._1
    }
}
