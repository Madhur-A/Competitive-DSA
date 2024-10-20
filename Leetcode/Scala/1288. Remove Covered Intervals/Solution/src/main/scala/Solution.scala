



object Solution {
    def removeCoveredIntervals(intervals: Array[Array[Int]]): Int = {
        val sortedIntervals = intervals.sortBy(e => (e(0), -e(1)))
        val Array (lower, upper) = sortedIntervals.head
        sortedIntervals.tail.foldLeft((0, lower, upper)) { case ((res, lo, hi), interval) =>
            val Array(left, right) = interval
            (hi < right) match {
                case  true => (res + 1, left, right)
                case false => (res, lo, hi)
            }
        }.head + 1
    }
}
