



object Solution {
    def subsetXORSum(nums: Array[Int]): Int = {
        val upper = 1 << nums.length

        def rx(index: Int, res: Int = 0): Int = (index == upper) match {
            case false => {
                val f = (0 to nums.length).filter(j => (((1 << j) & index) != 0))
                val e = if (f.isEmpty) 0 else f.map(e => nums(e)).reduce(_ ^ _)
                rx(index + 1, res + e)
            }
            case  true => res
        }

        rx(0)
    }
}
