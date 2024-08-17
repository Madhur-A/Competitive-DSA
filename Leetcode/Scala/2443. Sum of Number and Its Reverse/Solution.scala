



object Solution {
    def rev(num: Int): Int = {
        @annotation.tailrec
        def rx(n: Int, r: Int): Int = if (n <= 0) then r else rx(n / 10, r * 10 + (n % 10))
        rx(num, 0)
    }
    
    def sumOfNumberAndReverse(num: Int): Boolean = {
        val half = num / 2
        (half to num).foldLeft(false) { case (res, n) =>
            if (!res) then rev(n) + n == num else res
        }
    }
}

