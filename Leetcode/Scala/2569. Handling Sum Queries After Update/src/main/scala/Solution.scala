



class SegmentTree(nums: Array[Int]) {
    val n = nums.length
    val t = Array.fill(4 * n)(0)
    val l = Array.fill(4 * n)(0)

    build(0, 0, n - 1)

    def build(node: Int, start: Int, finish: Int): Unit = (start == finish) match {
        case true  => t(node) = nums(start)
        case false => {
            val mid = start + ((finish - start) >> 1)
            build(2 * node + 1, start, mid)
            build(2 * node + 2, mid + 1, finish)
            t(node) = t(2 * node + 1) + t(2 * node + 2)
        }
    }

    def pushDown(node: Int, start: Int, finish: Int): Unit = {
        if (l(node) != 0) {
            if ((l(node) & 1) == 1) {
                t(node) = (finish - start + 1) - t(node)
                if (start != finish) {
                    val (left, right) = (2 * node + 1, 2 * node + 2)
                    l(left) = l(left) ^ 1
                    l(right) = l(right) ^ 1
                }
            }
            l(node) = 0
        }
    }

    def update(left: Int, right: Int): Unit = updateRange(0, 0, n - 1, left, right)


    def updateRange(node: Int, start: Int, finish: Int, left: Int, right: Int): Unit = {
        pushDown(node, start, finish)
        (start, finish) match {
            case (start, finish) if (start > finish || start > right || finish < left) => ()
            case (start, finish) if (left <= start && finish <= right) => {
                t(node) = (finish - start + 1) - t(node)
                if (start != finish) {
                    l(2 * node + 1) ^= 1
                    l(2 * node + 2) ^= 1
                }
            }
            case _ => {
                val mid = start + ((finish - start) >> 1)
                updateRange(2 * node + 1, start, mid, left, right)
                updateRange(2 * node + 2, mid + 1, finish, left, right)
                t(node) = t(2 * node + 1) + t(2 * node + 2)
            }
        }
    }

    def getOnes(): Int = query(0, 0, n - 1, 0, n - 1)

    def query(node: Int, start: Int, finish: Int, left: Int, right: Int): Int = {
        if (start > finish || start > right || finish < left) return 0

        pushDown(node, start, finish)

        if (left <= start && finish <= right) return t(node)

        val mid = start + ((finish - start) >> 1)
        return query(2 * node + 1, start, mid, left, right) + query(2 * node + 2, mid + 1, finish, left, right)
    }
}

object Solution {
    def handleQuery(nums1: Array[Int], nums2: Array[Int], queries: Array[Array[Int]]): Array[Long] = {
        val st = new SegmentTree(nums1)

        var total = nums2.foldLeft(0L)(_ + _)

        queries.foldLeft((List[Long](), total)) { case ((res, curr), query) =>
            val Array(queryType, left, right) = query
            queryType match {
                case 1 => st.update(left, right); (res, curr)
                case 2 => (res, curr + left.toLong * st.getOnes())
                case 3 => (curr :: res, curr)
            }
        }.head.reverse.toArray
    }
}
