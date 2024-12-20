



object Solution {
    def sellingWood(r: Int, c: Int, prices: Array[Array[Int]]): Long = {
        val key: (Int, Int) => Int = (i, j) => (i * 211) + j
        val known = prices.map(e => (key(e(0), e(1)), e(2).toLong)).toMap
        val dp = Array.fill(r + 1, c + 1)(-1L)
        (0 to r).foreach(i => dp(i)(0) = 0L)
        (0 to c).foreach(j => dp(0)(j) = 0L)

        def rx(i: Int, j: Int): Long = (i, j) match {
            case (0, _) | (_, 0)     => 0
            case x if dp(i)(j) != -1 => dp(i)(j)
            case _                   => {
                val have = known.getOrElse(key(i, j), 0L)
                val hCuts = (1 until i).map(h => rx(h, j) + rx(i - h, j)).maxOption.getOrElse(0L)
                val vCuts = (1 until j).map(k => rx(i, k) + rx(i, j - k)).maxOption.getOrElse(0L)
                dp(i)(j) = Seq(have, hCuts, vCuts).max
                dp(i)(j)
            }
        }

        rx(r, c)
    }
}
