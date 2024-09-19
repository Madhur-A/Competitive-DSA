



object SolutionMLE { // it exceeds memory limit
    def rx(index: Int, target: Int, nums: List[Int], currPath: List[Int], allPaths: Set[List[Int]]): Set[List[Int]] = {
        if (currPath.sum == target) {
            allPaths ++ Set(currPath.sorted)
        } else if (nums.length <= index || currPath.sum > target) {
            Set()
        } else {
            val newPath = if (index < nums.length) nums(index) :: currPath else currPath
            rx(index + 1, target, nums, newPath, allPaths) ++ rx(index + 1, target, nums, currPath, allPaths)
        }
    }

    def combinationSum2(nums: Array[Int], target: Int): List[List[Int]] = {
        if (target <= nums.sum) {
            if (target == nums.sum) {
                List(nums.toList)
            } else { rx(0, target, nums.toList, List[Int](), Set[List[Int]]()).toList }
        } else { List() }
    }
}
