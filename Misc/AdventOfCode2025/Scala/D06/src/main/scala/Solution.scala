



object Solution {
    def retrieveInput(): Array[String] = {
        val text = scala.io.Source.fromFile("input")
        text.mkString.split('\n')
    }

    def combine(values: Seq[Long], isMux: Boolean): Long = isMux match {
        case  true => values.product
        case false => values.sum
    }

    def flushBuffer(buffer: List[String]): Long = {
        val (nums, op) = (buffer.init.map(_.toLong), buffer.last.last == '*')
        combine(nums :+ buffer.last.init.toLong, op)
    }

    def one(): Unit = {
        val grid = retrieveInput().map(_.trim.replaceAll("\\s+", " ").split(' '))
        val (r, c) = (grid.length, grid(0).length)

        val res =
            (0 until c).map { j =>
                val isMux = grid(r - 1)(j) == "*"
                combine((r - 2 to 0 by -1).map(i => grid(i)(j).toLong), isMux)
            }.sum

        println(s"res: $res, ${res == 5873191732773L}")
    }

    def two(): Unit = {
        val grid = retrieveInput()
        val (r, c) = (grid.length, grid(0).length)

        val columns =
            (c - 1 to 0 by -1).map { j =>
                (0 until r).map(i => if (grid(i)(j) == ' ') then '&' else grid(i)(j)).mkString.replace("&", "")
            }

        val (buffer, curr) =
            columns.foldLeft((List.empty[String], 0L)) {
                case ((buf, acc), col) if col.nonEmpty => (buf :+ col, acc)
                case ((buf, acc),   _)                 => (Nil, acc + flushBuffer(buf))
            }

        val res = curr + flushBuffer(buffer)

        println(s"res: $res, ${res == 11386445308378L}")
    }

    def main(args: Array[String]): Unit = {
        one()
        two()
    }
}
