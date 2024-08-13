



object Solution {
    def gcd(a: Long, b: Long): Long = if (b == 0) a else gcd(b, a % b)
    
    def subarrayGCD(nums: Array[Int], k: Int): Int = {
        nums.indices.foldLeft(0) { case (count, index) =>
            (index until nums.length).foldLeft((nums(index).toLong, count)) { case ((product, count), j) =>
                if(product >= k) {
                    val newProduct = gcd(product, nums(j))
                    (newProduct, count + (newProduct == k).compare(false))
                } else {
                    (product, count)
                }
            }._2
        }        
    }
}
