



object Solution {
    def construct2DArray(original: Array[Int], m: Int, n: Int): Array[Array[Int]] = {
        (m * n) match {
            case total if total == original.length => original.grouped(n).toArray
            case _                                 => Array.empty
        }
    }
}
