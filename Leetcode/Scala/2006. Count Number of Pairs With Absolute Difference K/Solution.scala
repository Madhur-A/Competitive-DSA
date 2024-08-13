



object Solution {
    def countKDifference(nums: Array[Int], k: Int): Int = {
        nums.foldLeft((0, Map.empty[Int, Int])) { case ((ans, g), num) => (ans + g.getOrElse(num - k, 0) + g.getOrElse(num + k, 0), g + (num -> (g.getOrElse(num, 0) + 1))) }._1
    }
}
