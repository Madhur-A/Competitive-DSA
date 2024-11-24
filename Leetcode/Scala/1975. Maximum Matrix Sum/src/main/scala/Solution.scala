



object Solution {
    def maxMatrixSum(matrix: Array[Array[Int]]): Long = {
        val (total, negs, minValue) = matrix.foldLeft((0L, 0, Long.MaxValue)) { case ((total, negs, minValue), row) =>
            row.foldLeft((total, negs, minValue)) { case ((total, negs, minValue), elem) =>
                (total + math.abs(elem), if (elem < 0) negs ^ 1 else negs, math.min(minValue, math.abs(elem)))
            }
        }

        total - negs * 2L * minValue
    }
}
