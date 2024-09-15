



object Solution {
    def findTheLongestSubstring(s: String): Int = {
        val vowels = "aeiou"
        val positions = Array.fill(32)(Int.MaxValue)
        positions.update(0, -1)

        s.zipWithIndex.foldLeft((0, 0)) { case ((res, state), (char, index)) =>
            val newState = vowels.indexOf(char) match {
                case -1 => state
                case  j => state ^ (1 << j)
            }
            val newRes = math.max(res, index - positions(newState))
            positions.update(newState, math.min(positions(newState), index))
            (newRes, newState)
        }.head
    }
}
