



object Solution { 
    def combinationSum2(candidates: Array[Int], target: Int): List[List[Int]] = {
        val values = candidates.sorted
        val result = new scala.collection.mutable.ListBuffer[List[Int]]()
        
        def rbx(index: Int, target: Int, current: List[Int]): Unit = {
            if (target == 0) {
                result += current
                return
            }
            
            var i = index
            while (i < values.length && values(i) <= target) {
                if (i > index && values(i) == values(i - 1)) {
                    i += 1
                } else {
                    rbx(i + 1, target - values(i), values(i) :: current)
                    i += 1
                }
            }
        }
        
        rbx(0, target, List())
        result.toList
    }

    def main(args: Array[String]) = {
        // val candidates = Array(10,1,2,7,6,1,5)
        // val target = 8
        val candidates = Array(3,1,3,5,1,1)
        val target = 8

        combinationSum2(candidates, target).foreach(row => println(s"Printing: $row"))
    }
}
