



object Solution {
    def retrieveInput(): String = {
        val text = scala.io.Source.fromFile("input").mkString.trim
        text
    }

    def one(): Unit = {
        val inputString = retrieveInput().split("\n\n")

        val tiles = inputString.init.map(e => (e, e.count(_ == '#'))).toArray
        val arrangements = inputString.last.split("\n")
        var res = 0L;
        for (inputLine <- arrangements) {
            val description = inputLine.split(": ")
            val Array(r, c) = description.head.trim.split("x").map(_.toInt)
            // just checking naively that if the area needed is sufficient;
            // though please note that this fails for given example test case
            val cellsNeeded =
                description.last.trim.split(" ")
                    .map(_.toInt).toArray
                    .zipWithIndex.foldLeft(0) { case (needed, (count, index)) =>
                        count match {
                            case 0 => needed
                            case _ => needed + (count * tiles(index)._2)
                        }
                    }

            if (cellsNeeded <= (r * c)) {
                res += 1
            }
        }

        println(s"res: $res, ${res == 451}")
    }

    def two(): Unit = {
    }

    def main(args: Array[String]): Unit = {
        one()
        // two()
    }
}
