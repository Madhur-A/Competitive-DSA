



object Solution {
    def combinationSum2(_nums: Array[Int], target: Int): List[List[Int]] = {
        val nums = _nums.sorted

        def dfs(index: Int, curr: Int, path: List[Int]): List[List[Int]] = {
            if (curr == target) then List(path)
            else if (index >= nums.length || curr > target) then Nil
            else {
                var i = index
                var result = List[List[Int]]()
                while (i < nums.length) {
                    if (!(i > index && nums(i) == nums(i-1))) {
                        result = result ::: dfs(i + 1, curr + nums(i), path ::: List(nums(i)))
                    }
                    i += 1
                }
                result
            }
        }

        dfs(0, 0, List.empty[Int])
    }
}


