



object Solution {
    def maxGoodNumber(nums: Array[Int]): Int = {
        nums.map(_.toBinaryString).permutations.map(_.mkString).map(e => Integer.parseInt(e, 2)).max
    }
}
