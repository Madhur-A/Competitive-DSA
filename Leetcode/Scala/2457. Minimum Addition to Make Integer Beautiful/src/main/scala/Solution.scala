



object Solution {
    def makeIntegerBeautiful(n: Long, k: Int): Long = {
        def rx(num: Long, mux: Long = 1L): Long = {
            val currS = num.toString
            val currV = currS.map(_.asDigit).sum.toLong
            currV <= k match {
                case  true => 0
                case false => mux * (10L - num % 10L) + rx(1L + (num / 10L), mux * 10L)
            }
        }
        rx(n, 1L)
    }
}
