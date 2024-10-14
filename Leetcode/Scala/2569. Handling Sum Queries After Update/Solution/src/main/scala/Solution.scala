



class SegmentTree(nums: Array[Int]) {
    val     n  = nums.length
    val (l, t) = (Array.fill(4 * n)(0), Array.fill(4 * n)(0))

    build(0, 0, n - 1)

    def build(node: Int, start: Int, finish: Int): Unit = (start == finish) match {
        case true  => { t(node) = nums(start) }
        case false => {
            val mid = start + ((finish - start) >> 1)
            build(2*node + 1, start, mid)
            build(2*node + 2, mid + 1, finish)
            t(node) = t(2*node + 1) + t(2*node + 2)
        }
    }

    def succession(node: Int, start: Int, finish: Int): Unit = (l(node) & 1) match {
        case 0 => l(node) = 0
        case _ => {
            t(node) = (finish - start + 1) - t(node)
            if (start != finish) {
                l(2*node + 1) ^= 1
                l(2*node + 2) ^= 1
            }
            l(node) = 0
        }
    }

    def rangeUpdate(left: Int, right: Int): Unit = rangeUpdate(0, 0, n - 1, left, right)

    def rangeUpdate(node: Int, start: Int, finish: Int, left: Int, right: Int): Unit = (start, finish) match {
        case (start, finish) if (left > finish || right < start)   => { succession(node, start, finish); () }
        case (start, finish) if (left <= start && finish <= right) => {
            succession(node, start, finish)
            t(node) = (finish - start + 1) - t(node)
            if (start != finish) {
                l(2*node + 1) ^= 1
                l(2*node + 2) ^= 1
            }
        }
        case _ => {
            succession(node, start, finish)
            val mid = start + ((finish - start) >> 1)
            rangeUpdate(2*node + 1, start, mid, left, right)
            rangeUpdate(2*node + 2, mid + 1, finish, left, right)
            t(node) = t(2*node + 1) + t(2*node + 2)
        }
    }

    def rangeEvaluate(): Int = rangeEvaluate(0, 0, n - 1, 0, n - 1)

    def rangeEvaluate(node: Int, start: Int, finish: Int, left: Int, right: Int): Int = (start, finish) match {
        case (start, finish) if (left > finish || right < start)    => 0
        case (start, finish) if (left <= start && finish <= right)  => t(node)
        case                                                     _  => {
            val mid = start + ((finish - start) >> 1)
            rangeEvaluate(2*node + 1, start, mid, left, right) + rangeEvaluate(2*node + 2, mid + 1, finish, left, right)
        }
    }
}

object SegmentTree {
    def apply(nums1: Array[Int], nums2: Array[Int], queries: Array[Array[Int]]): Array[Long] = {
        val (sg, total) = (new SegmentTree(nums1), nums2.foldLeft(0L)(_ + _))
        queries.foldLeft((List[Long](), total)) { case ((res, curr), query) =>
            val Array(queryType, left, right) = query
            queryType match {
                case 1 => sg.rangeUpdate(left, right); (res, curr)
                case 2 => (res, curr + left.toLong * sg.rangeEvaluate())
                case 3 => (curr :: res, curr)
            }
        }.head.reverse.toArray
    }
}

object Solution {
    def handleQuery(nums1: Array[Int], nums2: Array[Int], queries: Array[Array[Int]]): Array[Long] = SegmentTree(nums1, nums2, queries)
}
