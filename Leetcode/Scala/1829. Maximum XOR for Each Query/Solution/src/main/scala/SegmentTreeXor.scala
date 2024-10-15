



class SegmentTreeXor(nums: Array[Int]) {
    val (n, t) = (nums.length, Array.fill(nums.length * 4)(0))

    build(0, 0, n - 1)

    def build(node: Int, start: Int, finish: Int): Unit = (start != finish) match {
        case  true => {
            val middle = start + ((finish - start) >> 1)
            build(2*node + 1, start, middle)
            build(2*node + 2, middle + 1, finish)
            t(node) = t(2*node + 1) ^ t(2*node + 2)
        }
        case false => t(node) = nums(start)
    }

    def range_evaluate(left: Int, right: Int): Int = {
        range_evaluate(0, 0, n - 1, left, right)
    }

    def range_evaluate(node: Int, start: Int, finish: Int, left: Int, right: Int): Int = (start, finish) match {
        case (start, finish) if (start > right || finish < left)   => 0
        case (start, finish) if (left <= start && finish <= right) => t(node)
        case (start, finish) => {
            val middle = start + ((finish - start) >> 1)
            range_evaluate(2*node + 1, start, middle, left, math.min(right, middle)) ^ range_evaluate(2*node + 2, middle + 1, finish, math.max(middle + 1, left), right)
        }
    }
}

object SegmentTreeXor {
    def apply(nums: Array[Int], maximumBit: Int): Array[Int] = {
        val (seg, res) = (new SegmentTreeXor(nums), Array.fill(nums.length)(0))
        val mask = (1 << maximumBit) - 1

        nums.indices.foldLeft(res) { case (res, index) =>
            val xorRes = seg.range_evaluate(0, nums.length - index - 1)
            res(index) = xorRes ^ mask; res
        }
    }
}
