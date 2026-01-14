



object Solution {
    val dirs = Array(
            (0,1),(0,-1),(1,0),(-1,0),
            (1,1),(1,-1),(-1,1),(-1,-1));

    def retrieveInput(): Array[String] = {
        val text = scala.io.Source.fromFile("input").mkString
        text.split('\n').toArray
    }

    // procedural-style tracker
    def trackEach(grid: Array[Array[Char]]): Int = {
        val (r, c) = (grid.length, grid(0).length)
        val isValid: (Int, Int) => Boolean =
            (i, j) => i < r && j < c && i >= 0 && j >= 0

        var res = 0
        for (i <- (0 until r)) {
            for (j <- (0 until c)) {
                if (grid(i)(j) == '@') {
                    var count = 0
                    for (dir <- dirs) {
                        val (h, k) = (dir._1 + i, dir._2 + j)
                        if (isValid(h, k) && grid(h)(k) == '@') {
                            count += 1
                        }
                    }
                    if (count < 4) {
                        res += 1
                    }
                }
            }
        }

        return res
    }

    def trackRecurisve(grid: Array[Array[Char]]): Int = {
        val (r, c) = (grid.length, grid(0).length)
        val isValid: (Int, Int) => Boolean =
            (i, j) => i < r && j < c && i >= 0 && j >= 0

        var res = 0
        for (i <- (0 until r)) {
            for (j <- (0 until c)) {
                if (grid(i)(j) == '@') {
                    var count = 0
                    for (dir <- dirs) {
                        val (h, k) = (dir._1 + i, dir._2 + j)
                        if (isValid(h, k) && grid(h)(k) == '@') {
                            count += 1
                        }
                    }
                    if (count < 4) {
                        grid(i)(j) = '.'
                        res += 1
                    }
                }
            }
        }

        return if (res == 0) then res else res + trackRecurisve(grid)
    }

    def one(): Unit = {
        val grid = retrieveInput().map(e => e.toArray)
        val res = trackEach(grid)
        println(s"res: $res, ${res == 1540}")
    }

    def two(): Unit = {
        val grid = retrieveInput().map(e => e.toArray)
        val res = trackRecurisve(grid)
        println(s"res: $res, ${res == 8972}")
    }

    def main(args: Array[String]): Unit = {
        one()
        two()
    }
}
