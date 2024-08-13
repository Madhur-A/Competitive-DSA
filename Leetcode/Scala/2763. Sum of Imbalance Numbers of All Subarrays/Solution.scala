



object Solution {
    def sumImbalanceNumbers(nums: Array[Int]): Int = {
        val n = nums.length
        val seen  = Array.fill(n + 2)(-1)
        val left  = Array.fill(n + 2)(0)
        val right = Array.fill(n + 2)(n)

        nums.foldLeft(0) {
            case (index, num) =>
                left.update(index, math.max(seen(num + 1), seen(num)))
                seen.update(num, index)
                index + 1
        }

        nums.foldRight((0, n-1)) {
            case (num, (res, index)) =>
                right.update(num, index)
                val newRes = res + (index - left(index)) * (right(num + 1) - index)
                (newRes, index-1)
        }._1 - n * (n + 1) / 2
    }
}
