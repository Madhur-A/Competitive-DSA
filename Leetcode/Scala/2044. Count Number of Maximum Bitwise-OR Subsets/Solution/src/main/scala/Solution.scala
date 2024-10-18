



object Solution {
    def countMaxOrSubsets(nums: Array[Int]): Int = {
        val n = nums.length
        val u = 1 << n
        val maxOr = nums.scanLeft(0)(_ | _).max

        def dfs(index: Int, curr: Int = 0): Int = (index == n) match {
            case false => dfs(index + 1, curr | nums(index)) + dfs(index + 1, curr)
            case true  => (curr == maxOr) match {
                case true  => 1
                case false => 0
            }
        }

        dfs(0)

        // (0 until u).foldLeft(0) { case (res, index) =>
        //     (0 until n).foldLeft(0) { case (orred, j) =>
        //         ((1 << j) & index) match {
        //             case 0 => orred
        //             case _ => orred | nums(j)
        //         }
        //     } match {
        //         case x if x == maxOr => res + 1
        //         case x               => res
        //     }
        // }
    }
}
