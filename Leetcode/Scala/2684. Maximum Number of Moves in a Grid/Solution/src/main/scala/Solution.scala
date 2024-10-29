



// certainly NOT functional

object Solution {
    def maxMoves(grid: Array[Array[Int]]): Int = {
        val (r, c) = (grid.length, grid.head.length)
        val dp = Array.fill(r, c)(-1)

        def isValid(i: Int, j: Int, pastValue: Int): Boolean = {
            (i  < r) && (j  < c) &&
            (0 <= i) && (0 <= j) && grid(i)(j) > pastValue
        }

        def traverse(i: Int, j: Int, pastValue: Int): Int = isValid(i, j, pastValue) match {
            case  true => dp(i)(j) match {
                case -1 => {
                    dp(i)(j) = 1 + List(
                        traverse(i - 1, j + 1, grid(i)(j)),
                        traverse(i,     j + 1, grid(i)(j)),
                        traverse(i + 1, j + 1, grid(i)(j))
                    ).max
                    dp(i)(j)
                }
                case  _ => dp(i)(j)
            }
            case false => -1
        }

        (0 to r - 1).foldLeft(0) { case (res, index) =>
            math.max(res, traverse(index, 0, grid(index)(0) - 1))
        }
    }
}
