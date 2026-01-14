



object Solution {
    def retrieveInput(): Array[String] = {
        val text = scala.io.Source.fromFile("input").mkString
        text.split('\n')
    }

    def startPos(grid: Array[Array[Char]]): (Int, Int) = {
        val (r, c) = (grid.length, grid(0).length)
        var (x, y) = (-1, -1)
        var found = false
        for (i <- (0 until r)) {
            for (j <- (0 until c)) {
                if (!found && grid(i)(j) == 'S') {
                    x = i; y = j;
                    found = true
                }
            }
        }

        return (x, y)
    }

    // procedural DP
    def count(grid: Array[Array[Char]], curr: (Int, Int)): (Long, Long) = {
        val (r, c) = (grid.length, grid(0).length)
        val (x, y) = curr
        val (t, u) =
               (scala.collection.mutable.Set[Int](),
                scala.collection.mutable.Set[Int]())
        val (dp, dq) =
            (Array.fill(c)(0L), Array.fill(c)(0L))

        dp(y) += 1
        u.add(y)
        var res = 0L
        for (i <- (x + 1 until r)) {
            t.addAll(u)
            u.clear()
            while (t.nonEmpty) {
                val j = t.head; t.remove(t.head)
                val cell = grid(i)(j)
                if (cell == '^') {
                    res += 1
                    if (j     > 0) { u.add(j - 1); dq(j - 1) += dp(j) }
                    if (j + 1 < c) { u.add(j + 1); dq(j + 1) += dp(j) }
                } else {
                    u.add(j)
                    dq(j) += dp(j)
                }
            }

            System.arraycopy(dq, 0, dp, 0, dp.length)
            java.util.Arrays.fill(dq, 0L)
        }

        return (res, dp.sum) // pure imperative code (lol!)
    }

    def solve(): (Long, Long) = {
        val grid = retrieveInput().map(e => e.toArray)
        count(grid, startPos(grid))
    }

    def one(): Unit = {
        val (res, _) = solve()
        println(s"res: $res, ${res == 21L || res == 1656L}")
    }

    def two(): Unit = {
        val (_, res) = solve()
        println(s"res: $res, ${res == 40L || res == 76624086587804L}")
    }


    def main(args: Array[String]): Unit = {
        one()
        two()
    }
}
