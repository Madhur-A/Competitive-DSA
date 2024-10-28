



// certainly NOT functional

object Solution {
    def canPartition(nums: Array[Int]): Boolean = (nums.sum & 1) match {
        case 1 =>  false
        case _ =>  {
            val tg = nums.sum >> 1
            val dp = Array(true) ++ Array.fill(tg)(false)
            nums.foldLeft(dp) { case (dp, num) =>
                dp(tg) match {
                    case  true => dp
                    case false => {
                        (tg to num by -1).foreach { subTarget =>
                            dp(subTarget) = dp(subTarget) || dp(subTarget - num)
                        }; dp
                    }
                }
            }.last
        }
    }
}
