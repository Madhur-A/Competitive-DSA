



object Solution {
    def canJump(nums: Array[Int]): Boolean = {
        nums.foldLeft((true, 0, 0)) { case ((res, index, maxSoFar), num) =>
            res match {
                case false => (res, index, maxSoFar)
                case  true => {
                    val newRes = maxSoFar >= Math.min(index, nums.length - 1)
                    (newRes, index + 1, Math.max(maxSoFar, index + num))
                }
            }
        }.head
    }
}
