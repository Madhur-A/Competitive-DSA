



object Solution {
    def makeIntegerBeautiful(n: Long, k: Int): Long = {
        def rx(num: Long, mux: Long = 1L): Long = {
            val curr = num.toString.map(_.asDigit).sum.toLong
            curr <= k match {
                case  true => 0
                case false => mux * (10L - num % 10L) + rx(1L + (num / 10L), mux * 10L)
            }
        }
        rx(n, 1L)
    }
}
