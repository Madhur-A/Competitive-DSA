



// TODO
// 37/77 this is incorrect

class Fenwick(nums: Array[Int]) {
    val n = nums.length + 1
    val f = Array.fill(n)(0)
    val g = Array.fill(n)(0)
    val u = Array.fill(n)(0)

    for (i <- 1 until n) {
        f(i) += nums(i - 1)
        val j = i + (i & -i)
        if (j < n) f(j) += f(i)
    }

    def add(arr: Array[Int], index: Int, value: Int): Unit = {
        var i = index
        while (i < n) {
            arr(i) += value
            i += i & -i
        }
    }

    def sum(arr: Array[Int], index: Int): Int = {
        var res = 0
        var i = index
        while (i > 0) {
            res += arr(i)
            i -= i & -i
        }
        res
    }

    def updateRange(left: Int, right: Int): Unit = {
        add(g, left + 1, 1)
        add(g, right + 2, -1)
        add(u, left + 1, left)
        add(u, right + 2, -(right + 1))
    }

    def getOnes(): Int = {
        val total = sum(f, n - 1)
        val updates = sum(g, n - 1) * (n - 1) - sum(u, n - 1)
        total + updates
    }
}

object Fenwick {
    def apply(nums1: Array[Int], nums2: Array[Int], queries: Array[Array[Int]]): Array[Long] = {
    // def handleQuery(nums1: Array[Int], nums2: Array[Int], queries: Array[Array[Int]]): Array[Long] = {
        val fw = new Fenwick(nums1)
        var total = nums2.foldLeft(0L)(_ + _)

        queries.foldLeft((List[Long](), total)) { case ((res, curr), query) =>
            query(0) match {
                case 1 => fw.updateRange(query(1), query(2)); (res, curr)
                case 2 => (res, curr + query(1).toLong * fw.getOnes())
                case 3 => (curr :: res, curr)
            }
        }.head.reverse.toArray
    }
}
