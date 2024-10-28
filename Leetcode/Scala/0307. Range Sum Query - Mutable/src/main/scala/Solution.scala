



// Ha! NOT Functional, lol!

class NumArray(nums: Array[Int]) {
    val n = nums.length
    val t = Array.fill(4 * n)(0)
    build(0, 0, n - 1)

    def build(node: Int, start: Int, finish: Int): Unit = (start == finish) match {
        case true  => t(node) = nums(start)
        case false => {
            val mid = start + ((finish - start) >> 1)
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, finish)
            t(node) = t(2 * node + 1) + t(2 * node + 2)
        }
    }

    def update(index: Int, value: Int): Unit = update(0, 0, n - 1, index, value)

    def update(node: Int, start: Int, finish: Int, index: Int, value: Int): Unit = (start == finish) match {
        case true  => t(node) = value
        case false => {
            val mid = start + ((finish - start) >> 1)
            (index <= mid && start <= index) match {
                case true  => update(2 * node + 1, start, mid, index, value)
                case false => update(2 * node + 2, mid + 1, finish, index, value)
            }
            t(node) = t(2 * node + 1) + t(2 * node + 2)
        }
    }

    def sumRange(left: Int, right: Int): Int = sumInRange(0, 0, n - 1, left, right)

    def sumInRange(node: Int, start: Int, finish: Int, left: Int, right: Int): Int = {
        if (start > right || finish < left) { return 0 }
        if (left <= start && finish <= right) { return t(node); }
        val mid = start + ((finish - start) >> 1)
        return sumInRange(2 * node + 1, start, mid, left, right) + sumInRange(2 * node + 2, mid + 1, finish, left, right)
    }
}
