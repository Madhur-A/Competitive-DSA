



object Solution { // there is nothing functional about this solution
    def combinationSum2(_nums: Array[Int], target: Int): List[List[Int]] = {
        val nums = _nums.sorted
        val  ans = scala.collection.mutable.ListBuffer[List[Int]]()

        def dfs(index: Int, curr: Int, path: List[Int]): Unit = {
            if (curr == target) then {
                ans += path
                return
            }
            if (index >= nums.length || curr > target) then {
                return
            }

            var i = index
            while (i < nums.length) {
                if (! (i > index && nums(i) == nums(i-1))) then {
                    dfs(i + 1, curr + nums(i), path :+ nums(i))    
                }
                i += 1
            }
        }

        dfs(0, 0, List.empty[Int])
        ans.toList
    }
}
