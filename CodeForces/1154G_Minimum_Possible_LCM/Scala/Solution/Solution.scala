



object Solution {
    def main(args: Array[String]): Unit = {
        val reader = scala.io.StdIn
        val      n = reader.readLine.toInt
        val  index = Array.fill(10000005)(0)
        val   nums = reader.readLine.split(" ").map(_.toInt)
        var (ans, x, y) = (Long.MaxValue, 0, 0)

        for (i <- 1 to n) {
            val a = nums(i - 1)
            if (index(a) != 0) {
                if (a < ans) {
                    ans = a; x = index(a); y = i;
                }
            } else { index(a) = i }
        }

        for (i <- 1 to 10000001) {
            var a = 0
            for (j <- i to 10000001 by i) {
                if (index(j) != 0) {
                    if (a != 0) {
                        if (a.toLong * j / i < ans) {
                            ans = a.toLong * j / i; x = index(a); y = index(j)
                        }
                        // break
                    } else { a = j }
                }
            }
        }

        if (x > y) {
            val temp = x;
            x = y
            y = temp
        }

        println(s"$x $y")
    }
}
