



object Solution {
    def getWinner(nums: Array[Int], k: Int): Int = {
        val maxElement = nums.max
        def rx(curr: Int, next: Array[Int], count: Int = 0): Int = ((curr == maxElement) || (count == k)) match {
            case false => (curr > next.head) match {
                case  true => rx(curr, next.tail, count + 1)
                case false => rx(next.head, next.tail, 1)
            }
            case  true => curr
        }
        rx(nums.head, nums.tail)
    }
}
