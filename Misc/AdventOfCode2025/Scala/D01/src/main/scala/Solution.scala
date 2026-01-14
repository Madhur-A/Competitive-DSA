



object Solution {
    def retrieveInput(): Array[Int] = {
        val  text = scala.io.Source.fromFile("input").mkString
        text.replace("L", "-").replace("R", "").split('\n').map(_.toInt).toArray()
    }

    def one(): Unit = {
        val lines = retrieveInput()

        val (res, _) =
            lines.foldLeft((0, 50)) { case ((res, total), num) =>
                val newSum = (100 + total + num) % 100
                newSum match {
                    case 0 => (res + 1, newSum)
                    case _ => (res, newSum)
                }
            }

        println(s"res: $res, ${res == 1036}")
    }

    def two(): Unit = {
        val lines = retrieveInput()

        val (res, _) =
            lines.foldLeft((0, 50)) { case ((res, total), num) =>
                val revs = Math.abs(num) / 100
                val rems = Math.abs(num) % 100
                val ncnt = res + revs // new counts

                num match {
                    case dial if (dial != 0) => {
                        val candidate = if (dial < 0) then total - rems else total + rems
                        val extracRev = if (total != 0 && (candidate < 1 || candidate > 99)) then 1 else 0
                        (ncnt + extracRev, (candidate + 100) % 100)
                    }
                    case                 _ => (ncnt, total + rems)
                }
            }

        println(s"res: $res, ${res == 6228}")
    }

    def main(args: Array[String]): Unit = {
        one()
        two()
    }
}
