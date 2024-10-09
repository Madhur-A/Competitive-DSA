



// both of the following solutions are MLE

object SolutionMLE { // passed 54/118
    def isValid(nums: List[Int]): Boolean = nums.length match {
        case 0 => true
        case 1 => false
        case 2 => (nums(0) == nums(1))
        case 3 => (nums(0) == nums(1) && nums(1) == nums(2)) || (nums(1) - 1 == nums(0) && nums(1) + 1 == nums(2))
        case _ => {
            (isValid(nums.take(2)) && isValid(nums.drop(2))) || (isValid(nums.take(3)) && isValid(nums.drop(3)))
        }
    }

    def validPartition(nums: Array[Int]): Boolean = isValid(nums.toList)
}


object SolutionMLE { // also passed 54/118
    def isValid(nums: Array[Int]): Boolean = nums.length match {
        case 0 => true
        case 1 => false
        case 2 => (nums(0) == nums(1))
        case 3 => (nums(0) == nums(1) && nums(1) == nums(2)) || (nums(1) - 1 == nums(0) && nums(1) + 1 == nums(2))
    }

    def validPartition(nums: Array[Int]): Boolean = (nums.length <= 3) match {
        case true  =>  isValid(nums)
        case false => (isValid(nums.take(2)) || isValid(nums.take(3))) match {
            case true  => isValid(nums.take(2)) && isValid(nums.take(3)) match {
                case true  => validPartition(nums.drop(2)) || validPartition(nums.drop(3))
                case false => isValid(nums.take(2)) match {
                    case true  => validPartition(nums.drop(2))
                    case false => validPartition(nums.drop(3))
                }
            }
            case false => false
        }
    }
}
