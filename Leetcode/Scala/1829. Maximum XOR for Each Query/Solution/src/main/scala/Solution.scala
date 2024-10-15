



object Solution {
    def getMaximumXor(nums: Array[Int], maximumBit: Int): Array[Int] = {
        val mask = (1 << maximumBit) - 1
        nums.scanLeft(0)(_ ^ _).reverse.dropRight(1).map(_ ^ mask)
    }
}
