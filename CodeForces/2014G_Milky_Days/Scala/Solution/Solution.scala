



import scala.collection.mutable.ArrayBuffer
import scala.collection.mutable.Map

object Solution {
    def main(args: Array[String]): Unit = {
        val reader = scala.io.StdIn
        val  cases = reader.readInt
        val  diary = Map[Long, Long]()

        for (_ <- 1 to cases) {
            val Array(n, m, k) = reader.readLine.split(" ").map(_.toLong)
            diary.clear
            diary(Long.MaxValue) = 0
            for (_ <- 1L to n) {
                val Array(day, amount) = reader.readLine.split(" ").map(_.toLong)
                diary(day) = amount
            }

            solb(diary, m, k)
        }
    }

    def solb(g: Map[Long, Long], m: Long, k: Long): Unit = {
        val t = ArrayBuffer[(Long, Long)]()
        var (res, current, available) = (0L, 1L, 0L)

        for (day <- g.keys.toSeq.sorted) { // for (day <- g.keySet) {
            val amount = g(day)
            while (t.nonEmpty && current < day) {
                val (d, have) = t.last
                t.remove(t.length - 1)
                if (current - d <= k - 1) {
                    available = if (current < d) 0 else available
                    current   = math.max(current, d)
                    if (m > available + have) {
                        available += have
                    } else {
                        val minSpoilt = math.min(d + k, day)
                        val totalDays = current + (have + available - m) / m + 1
                        val actualCnt = math.min(minSpoilt, totalDays)
                        val remaining = have + available - (actualCnt - current) * m
                        if (remaining > 0) {
                            t += ((d, remaining))
                        }
                        res += actualCnt - current
                        available = 0
                        current = actualCnt
                    }
                }
            }
            t += ((day, amount))
        }

        println(res)
    }
}
