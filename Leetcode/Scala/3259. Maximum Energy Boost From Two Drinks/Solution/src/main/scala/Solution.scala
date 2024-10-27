



object Solution {
    def maxEnergyBoost(A: Array[Int], B: Array[Int]): Long = {
        val n = A.length
        def rx(maxA: Long, maxB: Long, index: Int = 0): Long = index < n match {
            case true => rx(math.max(maxB, maxA + B(index)), math.max(maxA, maxB + A(index)), index + 1)
            case    _ => math.max(maxA, maxB)
        }

        rx(0, 0)
    }
}
