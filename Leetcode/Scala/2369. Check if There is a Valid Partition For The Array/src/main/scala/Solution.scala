



// dp bottom-up
object Solution {
    def isValid(nums: Array[Int]): Boolean = nums.length match {
        case 2 => (nums(0) == nums(1))
        case _ => (nums(0) == nums(1) && nums(1) == nums(2)) || (nums(1) - 1 == nums(0) && nums(1) + 1 == nums(2))
    }

    def validPartition(nums: Array[Int]): Boolean = (nums.length <= 3) match {
        case true  => isValid(nums)
        case false => {
            val dp = Array.fill(nums.length)(false)
            dp(1) = isValid(nums.take(2))
            dp(2) = isValid(nums.take(3))
            if (dp(1) || dp(2)) {
                for (x <- 3 until nums.length) {
                    dp(x) =
                        (dp(x - 2) && (nums(x) == nums(x - 1))) || (isValid(Array(nums(x - 2), nums(x - 1), nums(x))) && dp(x - 3))
                }
            }
            dp.last
        }
    }
}


// dp top-down
object Solution {
    def isValid(nums: Array[Int], start: Int, len: Int): Boolean = len match {
        case 2 => nums(start) == nums(start + 1)
        case 3 => (nums(start) == nums(start + 1) && nums(start + 1) == nums(start + 2)) ||
                 (nums(start + 1) - 1 == nums(start) && nums(start + 1) + 1 == nums(start + 2))
    }

    def validPartition(nums: Array[Int]): Boolean = {
        val have = collection.mutable.Map[Int, Boolean]()

        def rx(index: Int): Boolean = have.contains(index) match {
            case true  => have(index)
            case false => {
                val len = nums.length
                have(index) = len match {
                    case len if (len <= index)      => true
                    case len if (len  - index) <= 1 => false
                    case                          _ => {
                        val (takeTwo, takeThree) = (index + 1 < nums.length && isValid(nums, index, 2),
                                                    index + 2 < nums.length && isValid(nums, index, 3))
                        (takeTwo || takeThree) match {
                            case false => false
                            case true  => (takeTwo && takeThree) match {
                                case true  => rx(index + 2) || rx(index + 3)
                                case false => takeTwo match {
                                    case  true => rx(index + 2)
                                    case false => rx(index + 3)
                                }
                            }
                        }
                    }
                }
                have(index)
            }
        }

        rx(0)
    }
}
