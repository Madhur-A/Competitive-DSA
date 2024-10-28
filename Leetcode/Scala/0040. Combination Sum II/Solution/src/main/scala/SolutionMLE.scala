



// 172 / 176 test cases passed
// exceeds memory limit

object SolutionMLE {
    def rx(index: Int, target: Int, nums: List[Int], currPath: List[Int], allPaths: Set[List[Int]]): Set[List[Int]] = (currPath.sum == target) match {
        case  true => allPaths ++ Set(currPath.sorted)
        case false => (nums.length <= index || currPath.sum > target) match {
            case  true => Set()
            case false => {
                val newPath = (index < nums.length) match {
                    case true => nums(index) :: currPath
                    case false => currPath
                }
                rx(index + 1, target, nums, newPath, allPaths) ++ rx(index + 1, target, nums, currPath, allPaths)
            }
        }
    }

    def combinationSum2(nums: Array[Int], target: Int): List[List[Int]] = (target <= nums.sum) match {
        case false => List()
        case  true => (target == nums.sum) match {
            case  true => List(nums.toList)
            case false => rx(0, target, nums.toList, List[Int](), Set[List[Int]]()).toList
        }
    }
}
