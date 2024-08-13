



object Solution {
    def countSubarrays(nums: Array[Int], k: Int): Int = {
        val n: Int = nums.length;
        val index: Int = nums.indexOf(k)
        val seen = scala.collection.mutable.Map[Int, Int]()
        
        val rhs = 
            nums.drop(index+1).foldLeft((0, 0)) {
                case((count, res), num) => {
                    val newCount = if (num > k) then count + 1 else count - 1
                    val   newRes = if (newCount >= 0 && newCount <= 1) then res + 1 else res
                    seen(n + newCount) = seen.getOrElse(n + newCount, 0) + 1
                    (newCount, newRes)
                }
            }._2
        
        val lhs = 
            nums.take(index).foldRight((0, 0)) {
                case(num, (count, res)) => {
                    val newCount = if (num > k) then count + 1 else count - 1
                    val   newRes = if (newCount >= 0 && newCount <= 1) then res + 1 else res
                    (newCount, newRes + seen.getOrElse(n-newCount, 0) + seen.getOrElse(n-newCount+1, 0))
                }
            }._2;
        
        lhs + rhs + 1;
    }
}
