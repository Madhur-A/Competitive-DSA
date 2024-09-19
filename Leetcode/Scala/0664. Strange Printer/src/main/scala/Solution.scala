



object Solution {
    def strangePrinterTD(s: String): Int = {
        val  n = s.length
        val dp = collection.mutable.Map.empty[(Int, Int, Int), Int]

        def rx(i: Int, j: Int, k: Int): Int = {
            if (i > j) then { 0 } else {
                dp.getOrElseUpdate((i, j, k), {
                    if (s(i).toInt == k) then { rx(i + 1, j, k) } else
                    if (s(j).toInt == k) then { rx(i, j - 1, k) } else {
                        (i to j).foldLeft(n) { case (res, mid) =>
                            math.min(res, 1 + rx(i, mid, s(i).toInt) + rx(mid + 1, j, k))
                        }
                    }})
            }
        }

        rx(0, n - 1, '*'.toInt)
    }

    def strangePrinterBU(s: String): Int = {
        val (n, dp) = (s.length, Array.fill(s.length, s.length)(1000))
        (n - 1 to 0 by -1).foreach { i =>
            dp(i)(i) = 1
            (i + 1 until n).foreach { j =>
                if (s(i) == s(j)) {
                    dp(i)(j) = dp(i)(j - 1)
                } else {
                    (i until j).foreach { k =>
                        dp(i)(j) = math.min(dp(i)(j), dp(i)(k) + dp(k + 1)(j))
                    }
                }
            }
        }

        dp.head.last
    }

    def strangePrinter(s: String): Int = {
        // strangePrinterTD(s)
        strangePrinterBU(s)
    }
}
