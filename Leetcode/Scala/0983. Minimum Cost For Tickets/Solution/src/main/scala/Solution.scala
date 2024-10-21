



object Solution {
    def mincostTickets(days: Array[Int], costs: Array[Int]): Int = {
        val  n = days.length
        val dp = Array.fill(days.length + 1, 3)(Int.MaxValue)
        val permit = Array(1, 7, 30)
        dp(0)(0) = 0; dp(0)(1) = 0; dp(0)(2) = 0;

        def findIndex(target: Int): Int = {
            def go(left: Int, right: Int): Int = (left < right) match {
                case  true => {
                    val mid = left + ((right - left) >> 1)
                    (days(mid) < target) match {
                        case  true => go(mid + 1, right)
                        case false => go(left, mid)
                    }
                }
                case false => left
            }
            go(0, n)
        }

        // bottom-up
        for (i <- 0 to n - 1) {
            for (j <- 0 to 2; k <- 0 to 2) {
                val nextIndex = findIndex(days(i) + permit(k))
                dp(nextIndex)(j) = math.min(dp(nextIndex)(j), costs(k) + dp(i)(j))
            }
        }

        dp(n)(0)

        // top-down
//        def rx(index: Int, travelPass: Int): Int = (index < n) match {
//             case  true => {
//                 dp(index)(travelPass) match {
//                     case Int.MaxValue => {
//                         dp(index)(travelPass) = math.min(
//                             costs(0) + rx(findIndex(days(index) +  1), 0),
//                             math.min(
//                                 costs(1) + rx(findIndex(days(index) +  7), 1),
//                                 costs(2) + rx(findIndex(days(index) + 30), 2))
//                         )
//                         dp(index)(travelPass)
//                     }
//                     case            _ => dp(index)(travelPass)
//                 }
//             }
//             case false => 0
//         }

//         rx(0, 0)
    }
}
