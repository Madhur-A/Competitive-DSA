



object Solution {
    def canPartition(nums: Array[Int]): Boolean = {
        val (total, target) = (nums.sum, nums.sum / 2)
        total match {
            case x if (total & 1) == 1 =>  false
            case _                     =>  {
                val dp = Array.fill(target + 1)(false)
                dp.update(0, true)
                nums.foldLeft(dp) { case (dp, num) =>
                    if (!dp(target)) {
                        (target to num by -1).foreach { subTarget =>
                            dp.update(subTarget, dp(subTarget) | dp(subTarget - num))
                        }
                    }; dp
                }.last
            }
        }
    }
}
