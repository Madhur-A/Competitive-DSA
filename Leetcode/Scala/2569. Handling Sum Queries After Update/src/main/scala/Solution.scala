



class SegmentTree(nums: Array[Int]) {
    val n = nums.length
    val t = Array.fill(4 * n)(0)
    val l = Array.fill(4 * n)(0)

    build(0, 0, n - 1)

    def coupling(node: Int): (Int, Int) = (2 * node + 1, 2 * node + 2)

    def build(node: Int, start: Int, finish: Int): Unit = (start == finish) match {
        case true  => t(node) = nums(start)
        case false => {
            val mid = start + ((finish - start) >> 1)
            val (gauche, droit) = coupling(node)
            build(gauche, start, mid)
            build(droit, mid + 1, finish)
            t(node) = t(2 * node + 1) + t(2 * node + 2)
        }
    }

    def propagate(node: Int, start: Int, finish: Int): Unit = node match {
        case node if (l(node) == 0) => ()
        case node                   => (l(node) & 1) match {
            case 0 => l(node) = 0
            case _ => {
                t(node) = (finish - start + 1) - t(node)
                if (start != finish) {
                    val (left, right) = coupling(node)
                    l(left)  = l(left)  ^ 1
                    l(right) = l(right) ^ 1
                }
                l(node) = 0
            }
        }
    }

    def rangeUpdate(left: Int, right: Int): Unit = rangeUpdate(0, 0, n - 1, left, right)

    def rangeUpdate(node: Int, start: Int, finish: Int, left: Int, right: Int): Unit = {
        propagate(node, start, finish)
        (start, finish) match {
            case (start, finish) if (left > finish || right < start || start > finish) => ()
            case (start, finish) if (left <= start && finish <= right) => {
                t(node) = (finish - start + 1) - t(node)
                if (start != finish) {
                    val (gauche, droit) = coupling(node)
                    l(gauche) = l(gauche) ^ 1
                    l(droit)  = l(droit)  ^ 1
                }
            }
            case _ => {
                val mid = start + ((finish - start) >> 1)
                val (gauche, droit) = coupling(node)
                rangeUpdate(gauche, start, mid, left, right)
                rangeUpdate(droit, mid + 1, finish, left, right)
                t(node) = t(2 * node + 1) + t(2 * node + 2)
            }
        }
    }


    def countOfOnes(): Int = countOfOnes(0, 0, n - 1, 0, n - 1)

    def countOfOnes(node: Int, start: Int, finish: Int, left: Int, right: Int): Int = (start, finish) match {
        case (start, finish) if (left > finish || right < start || start > finish) => 0
        case                                                                     _ => (start, finish) match {
            case (start, finish) if (left <= start && finish <= right) => propagate(node, start, finish); t(node)
            case                                                    _  => {
                propagate(node, start, finish)
                val mid = start + ((finish - start) >> 1)
                val (gauche, droit) = coupling(node)
                countOfOnes(gauche, start, mid, left, right) + countOfOnes(droit, mid + 1, finish, left, right)
            }
        }
    }
}

object Solution {
    def handleQuery(nums1: Array[Int], nums2: Array[Int], queries: Array[Array[Int]]): Array[Long] = {
        val (sg, total) = (new SegmentTree(nums1), nums2.foldLeft(0L)(_ + _))
        queries.foldLeft((List[Long](), total)) { case ((res, curr), query) =>
            val Array(queryType, left, right) = query
            queryType match {
                case 1 => sg.rangeUpdate(left, right); (res, curr)
                case 2 => (res, curr + left.toLong * sg.countOfOnes())
                case 3 => (curr :: res, curr)
            }
        }.head.reverse.toArray
    }
}
