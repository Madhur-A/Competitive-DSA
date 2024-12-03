



object Solution {
    def addSpaces(s: String, spaces: Array[Int]): String = {
        val n = s.length + spaces.length;
        val res = Array.fill(n)('\u0000')

        (0 until n).foldLeft((res, 0, 0, 0, spaces)) { case ((res, i, j, x, spaces), _) =>
            i < spaces.length && spaces(i) == x match {
                case  true => {
                    res(j) = ' ';
                    (res, i + 1, j + 1, x, spaces)
                }
                case false => {
                    res(j) = s(x)
                    (res, i, j + 1, x + 1, spaces)
                }
            }
        }.head.mkString
    }
}

// MLE
// object Solution {
//     def addSpaces(s: String, spaces: Array[Int], err: Int = 0): String = spaces.isEmpty match {
//         case false => s.take(spaces.head - err) + " " + addSpaces(s.drop(spaces.head - err), spaces.tail, spaces.head)
//         case true  => s;
//     }
// }
