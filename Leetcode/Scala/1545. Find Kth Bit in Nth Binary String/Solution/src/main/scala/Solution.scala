



object Solution {
    def findKthBit(n: Int, k: Int): Char = (n, k) match {
        case (1, _) => '0'
        case (n, k) => {
            val l = (1 << n) - 1
            val h = (l >> 1) + 1
            (n, k) match {
                case (n, k) if (k == h) => '1'
                case (n, k) if (k <  h) => findKthBit(n - 1, k)
                case (n, k)             => findKthBit(n - 1, l - k + 1) match {
                    case '0' => '1'
                    case  _  => '0'
                }
            }
        }
    }
}
