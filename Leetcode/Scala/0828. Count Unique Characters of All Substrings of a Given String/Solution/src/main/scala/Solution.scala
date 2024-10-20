



 object Solution {
    def uniqueLetterString(s: String): Int = {
        s.zipWithIndex.foldLeft((0, 0, Array.fill(128)(0), Array.fill(128)(0))) { case ((res, sub, prev, curr), (char, index)) =>
            val newSub = sub + (index + 1) + prev(char.toInt) - 2 * curr(char.toInt)
            val newRes = res + newSub
            prev(char.toInt) = curr(char.toInt)
            curr(char.toInt) = index + 1
            (newRes, newSub, prev, curr)
        }.head
    }
}
