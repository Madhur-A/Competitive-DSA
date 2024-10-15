



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
        case (start, finish) if (start > right || finish < left || left > right)   => 0
        case (start, finish) if (left == start && right == finish) => t(node)
        case (start, finish) => {
            val middle = start + ((finish - start) >> 1)
            range_evaluate(2*node + 1, start, middle, left, math.min(middle, right)) ^ range_evaluate(2*node + 2, middle + 1, finish, math.max(middle + 1, left), right)
        }
    }

}

object SegmentTreeXor {
    def apply(nums: Array[Int], queries: Array[Array[Int]]): Array[Int] = {
        val seg = new SegmentTreeXor(nums)
        val res = Array.fill(queries.length)(0)
        queries.zipWithIndex.foldLeft(res) { case (res, (query, index)) =>
            val Array (left, right) = query
            res(index) = seg.range_evaluate(left, right); res
        }
    }
}

object Solution {
    def xorQueries(arr: Array[Int], queries: Array[Array[Int]]): Array[Int] = SegmentTreeXor(arr, queries)
}
