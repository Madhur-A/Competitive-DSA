



object Solution {
    def minInterval(intervals: Array[Array[Int]], queries: Array[Int]): Array[Int] = {
        val n = intervals.length
        val sortedIntervals = intervals.sortBy(e => (e(0), e(1)))
        val res = Array.fill(queries.length)(-1)
        val sortedQueries = queries.zipWithIndex.sortBy(_.head)

        val t = scala.collection.mutable.PriorityQueue.empty[(Int, Int)](Ordering.by(-_.head))
        var intervalIndex = 0

        for ((query, qIndex) <- sortedQueries) {
            while (intervalIndex < n && sortedIntervals(intervalIndex)(0) <= query) {
                val left = sortedIntervals(intervalIndex)(0)
                val right = sortedIntervals(intervalIndex)(1)
                t.enqueue((right - left + 1, right))
                intervalIndex += 1
            }
            while (t.nonEmpty && t.head.last < query) { t.dequeue() }
            if (t.nonEmpty) { res(qIndex) = t.head.head }
        }
        res
    }
}

// the following (quasi-functional) approach gives MLE
object Solution {
    def minInterval(intervals: Array[Array[Int]], queries: Array[Int]): Array[Int] = {
        val n = intervals.length
        val sortedIntervals = intervals.sortBy(e => (e(0), e(1)))
        val res = Array.fill(queries.length)(-1)
        val t = scala.collection.mutable.PriorityQueue.empty[(Int,Int)](Ordering.by(-_.head))

        queries.zipWithIndex.sortBy(_.head).foldLeft(sortedIntervals) { case (timePeriods, (query, qIndex)) =>
            val newTimePeriods =
                sortedIntervals.dropWhile { e =>
                    val Array(left, right) = e
                    val valid = (left <= query)
                    if (valid) { t.enqueue((right - left + 1, right)) }
                    valid
                }
            while (t.nonEmpty && t.head.last < query) { t.dequeue() }
            if (t.nonEmpty) { res(qIndex) = t.head.head }
            newTimePeriods
        }
        res
    }
}
