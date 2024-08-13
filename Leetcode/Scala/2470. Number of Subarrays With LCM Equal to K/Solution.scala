



object Solution {
    def gcd(a: Long, b: Long): Long = if (b == 0) a else gcd(b, a % b)
    def lcm(a: Long, b: Long): Long = (a * b) / gcd(a, b)

    def subarrayLCM(nums: Array[Int], k: Int): Int = {
        nums.indices.foldLeft(0) { case (count, index) =>
            nums.drop(index).foldLeft((1L, count)) { case ((product, count), num) =>
                if(product <= k) {
                    val newProduct = lcm(product, num)
                    (newProduct, count + (newProduct == k).compare(false))
                } else {
                    (product, count)
                }
            }._2
        }
    }
}
