



 object Solution {
    def uniqueLetterString(s: String): Int = {
        s.zipWithIndex.foldLeft((0, 0, Array.fill(128)(0), Array.fill(128)(0))) { case ((res, sub, prev, curr), (char, index)) =>
            val newSub = sub + (index + 1) + prev(char) - 2 * curr(char)
            val newRes = res + newSub
            prev(char) = curr(char)
            curr(char) = index + 1
            (newRes, newSub, prev, curr)
        }.head
    }
}
