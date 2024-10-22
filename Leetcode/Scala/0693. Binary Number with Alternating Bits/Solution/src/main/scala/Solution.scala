



object Solution {
    def hasAlternatingBits(n: Int, p: Int = -1): Boolean = n match {
        case 0 => if (p == -1) true else p == 1
        case _ => {
            val lastBit = (n & 1)
            val nextBit = if (p == -1) ((n >> 1) & 1) else p
            (lastBit, nextBit) match {
                case (1, 1) => false
                case (0, 0) => false
                case     _  => hasAlternatingBits(n >> 1, nextBit ^ 1)
            }
        }
    }
}
