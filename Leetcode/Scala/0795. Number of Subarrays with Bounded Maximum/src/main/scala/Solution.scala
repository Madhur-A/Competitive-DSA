



object Solution {
    def numSubarrayBoundedMax(nums: Array[Int], left: Int, right: Int): Int = {
        nums.foldLeft((0, -1, -1, 0)) {
            case((total, l, r, index), num) => {
                val i = if(num > right) then index else l
                val j = if(num >= left) then index else r
                (total + (j - i), i, j, index + 1)
            }
        }.head
    }
}
