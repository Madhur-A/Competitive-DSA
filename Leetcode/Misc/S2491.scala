



object Solution {
    def dividePlayers(skills: Array[Int]): Long = {
        val required = skills.sorted.head + skills.sorted.last
        val paired = skills.sorted.take(skills.length >> 1).zip(skills.sorted.drop(skills.length >> 1).reverse)
        if (paired.forall((a, b) => a + b == required)) {
            paired.map((a, b) => a * 1L * b).foldLeft(0L)(_ + _)
        } else { -1L }
        
        // def rx(nums: Array[Int], res: Long = 0L): Long = nums match {
        //     case Array() => res
        //     case       _ => {
        //         nums.head + nums.last match {
        //             case x if (x == required) => rx(nums.tail.dropRight(1), res + nums.head * nums.last)
        //             case x                    => -1L
        //         }
        //     }
        // }
        // rx(skills.sorted)
    }
}
