



// certainly NOT functional

object Solution {
    def countSquares(matrix: Array[Array[Int]]): Int = {
        val (r, c) = (matrix.length, matrix.head.length)
        (1 to r).foldLeft((0, Array.fill(r + 1, c + 1)(0))) { case ((res, dp), i) =>
                ((1 to c).foldLeft(res) { case (res, j) =>
                    matrix(i - 1)(j - 1) match {
                        case 0 => res
                        case _ => {
                            dp(i)(j) = List(dp(i - 1)(j - 1), dp(i)(j - 1), dp(i - 1)(j)).min + 1
                            res + dp(i)(j)
                        }
                    }
                }, dp)
        }.head
    }
}
