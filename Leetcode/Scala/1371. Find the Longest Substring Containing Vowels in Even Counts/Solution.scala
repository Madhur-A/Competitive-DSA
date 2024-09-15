



// this is a superb question [!!]

object Solution {
    def findTheLongestSubstring(s: String): Int = {
        val nextState: (Int, Char) => Int = (state, char) => {
            val f = "aeiou".indexOf(char)
            if (f < 0) state else state ^ (1 << f)
        }
        
        s.zipWithIndex.foldLeft((0, 0, Map(0 -> -1))) { case ((res, state, positions), (char, index)) =>
            val newState = nextState(state, char)
            val newRes = math.max(res, index - positions.getOrElse(newState, Int.MaxValue))
            val newPositions = positions.updated(newState, math.min(positions.getOrElse(newState, Int.MaxValue), index))
            (newRes, newState, newPositions)
        }.head
    }
}
