



object Solution {
    def kthLargestValue(matrix: Array[Array[Int]], k: Int): Int = {
        val (r, c) = (matrix.length, matrix.head.length)
        val sums = Array.fill(r + 1, c + 1)(0)
        Array.tabulate(r + 1, c + 1) { (i, j) =>
            (i, j) match {
                case (i, j) if (i != 0 && j != 0) => {
                    sums(i)(j) = matrix(i - 1)(j - 1) ^ sums(i - 1)(j) ^ sums(i)(j - 1) ^ sums(i - 1)(j - 1); sums(i)(j)
                }
                case (i, j)                       => 0
            }
        }.flatten.sorted.reverse(k - 1)
    }
}
