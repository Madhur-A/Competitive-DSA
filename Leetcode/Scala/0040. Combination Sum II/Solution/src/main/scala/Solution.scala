



object Solution {
    def combinationSum2(candidates: Array[Int], target: Int): List[List[Int]] = {
        val values = candidates.sorted
        val result = new scala.collection.mutable.ListBuffer[List[Int]]()

        def rbx(index: Int, target: Int, currPath: List[Int]): Unit = {
            if (target == 0) { result += currPath; return }

            var i = index
            while (i < values.length && values(i) <= target) {
                if (i > index && values(i) == values(i - 1)) {
                    i += 1
                } else { rbx(i + 1, target - values(i), values(i) :: currPath); i += 1 }
            }
        }

        rbx(0, target, List())
        result.toList
    }
}
