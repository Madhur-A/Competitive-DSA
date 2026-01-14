



object Solution {
    val dirs = Array((1,0),(0,1),(-1,0),(0,-1))

    def retrieveInput(): Array[(Long, Long)] = {
        val text = scala.io.Source.fromFile("input").mkString
        text.split('\n').map(e => e.split(',').map(_.toLong)).map(e => (e(0), e(1)))
    }

    def one(): Unit = {
        val grid = retrieveInput(); // Array[(Long, Long)]
        val res =
            grid.indices.foldLeft(0L) { case (res, i) =>
                val next = i + 1
                val (x, y) = grid(i)
                (next until grid.length).foldLeft(res) { case (res, j) =>
                    val (h, k) = grid(j)
                    Math.max(res, (Math.abs(h - x) + 1L) * (Math.abs(y - k) + 1L))
                }
            }

        println(s"res: $res, ${res == 50L || res == 4771508457L}")
    }

    def two(): Unit = { // !!!!!!!!!!!!!!!!!! EXTREMELY INEFFICIENT (takes over 1 minute)
        val points = retrieveInput(); // Array[(Long, Long)]

        val xs = points.flatMap(p => Array(p._1, p._1 - 1, p._1 + 1)).distinct.sorted
        val ys = points.flatMap(p => Array(p._2, p._2 - 1, p._2 + 1)).distinct.sorted

        val (xi, yi) = (xs.zipWithIndex.toMap, ys.zipWithIndex.toMap)
        val (width, height) = (xs.length, ys.length)
        val grid = Array.fill(height, width)(0)

        points.indices.foreach(i => {
            val (a, b) = (points(i), points((i + 1) % points.length))

            val (x1, y1) = (xi(a._1), yi(a._2))
            val (x2, y2) = (xi(b._1), yi(b._2))

            if (x1 == x2) {
                val r = Math.min(y1, y2) to Math.max(y1, y2)
                r.foreach(y => grid(y)(x1) = 1)
            } else {
                val r = Math.min(x1, x2) to Math.max(x1, x2)
                r.foreach(x => grid(y1)(x) = 1)
            }
        })

        val isValid: (Int, Int) => Boolean =
            (i, j) => i < width && j < height && i >= 0 && j >= 0

        val t = scala.collection.mutable.Queue[(Int, Int)]()
        t.enqueue((0, 0))
        grid(0)(0) = -1

        while (t.nonEmpty) {
            val (y, x) = t.dequeue()
            for (dir <- dirs) {
                val (h, k) = (x + dir._1, y + dir._2)
                if (isValid(h, k) && grid(k)(h) == 0) {
                    grid(k)(h) = -1
                    t.enqueue((k, h))
                }
            }
        }

        val inside = (x: Int, y: Int) => grid(y)(x) != -1

        val red = points.map(p => (xi(p._1), yi(p._2), p._1, p._2))
        var res = 0L

        red.indices.foreach { i =>
            ((i + 1) until red.length).foreach { j =>
                val (x1i, y1i, x1, y1) = red(i)
                val (x2i, y2i, x2, y2) = red(j)

                if (x1i != x2i && y1i != y2i) {
                    val xsR = x1i.min(x2i) to x1i.max(x2i)
                    val ysR = y1i.min(y2i) to y1i.max(y2i)

                    var valid = true
                    for (y <- ysR) {
                        for (x <- xsR) {
                            if (valid) {
                                valid = valid & inside(x, y)
                            }
                        }
                    }

                    if (valid) {
                        val X = Math.abs(x1 - x2) + 1
                        val Y = Math.abs(y1 - y2) + 1
                        res = Math.max(res, X * Y)
                    }
                }
            }
        }

        println(s"res: $res, ${res == 24L || res == 1539809693L}")
    }

    def main(args: Array[String]): Unit = {
        one()
        two()
    }
}
