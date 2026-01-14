



object Solution {
    def retrieveInput(): String = {
        val text = scala.io.Source.fromFile("input").mkString
        text
    }

    def contentWithRanges(): (Array[Long], Array[(Long, Int)]) = {
        val nums = retrieveInput().split("\n\n")
        val contents =
            nums(1).split('\n').map(_.toLong).sorted
        val ranges =
            nums(0)
                .split('\n')
                .map(e => e.split('-').map(f => f.toLong))
                .map(g => (g(0), g(1)))
        val sweeps =
            ranges.flatMap { case (start, end) =>
                Array((start, 1), (end + 1, -1))
            }.sortBy { case (value, delta) => (value, -delta) }

        (contents, sweeps)
    }

    def one(): Unit = {
        val (contents, sweeps) = contentWithRanges()
        val events = sweeps ++ contents.map(content => (content, 0))
        val res =
            events.sortBy { case (value, delta) => (value, -delta) }
                .foldLeft((0, 0)) { case ((count, active), (_, delta)) =>
                    delta == 0 match {
                        case  true => (count + (if (active > 0) then 1 else 0), active)
                        case false => (count, active + delta)
                    }
                }._1

        println(s"res: $res, ${res == 874}")
    }

    def two(): Unit = {
        val (_, sweeps) = contentWithRanges()
        val res =
            sweeps.foldLeft((0L, 0L, 0)) { case ((total, prev, active), (curr, delta)) =>
                active > 0 match {
                    case  true => (total + curr - prev, curr, active + delta)
                    case false => (total, curr, active + delta)
                }
            }._1

        println(s"res: $res, ${res == 348548952146313L}")
    }

    def main(args: Array[String]): Unit = {
        one()
        two()
    }
}
