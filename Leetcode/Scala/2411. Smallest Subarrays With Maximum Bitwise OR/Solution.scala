



object Solution {
    def smallestSubarrays(nums: Array[Int]): Array[Int] = {
        val n: Int = nums.size
        var found: Array[Int] = Array.fill(30)(0)
        var   res: Array[Int] = Array.fill(n)(1)
        nums.foldRight(n-1) { case(num, index) => 
            (0 to 29).foldLeft(0) { case(_, j) =>
                val lastBit = (num >> j) & 1
                if(lastBit == 1) { found(j) = index }
                res(index) = math.max(res(index), found(j) - index + 1)
                j + 1
            }
            index - 1
        }
        res
    }
}
