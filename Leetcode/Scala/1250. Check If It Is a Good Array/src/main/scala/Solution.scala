



object Solution {
    def isGoodArray(nums: Array[Int]): Boolean = {
        def gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)
        nums.reduce(gcd) == 1
    }
}
