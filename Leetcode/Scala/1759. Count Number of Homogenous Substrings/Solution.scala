



object Solution {
    def countHomogenous(s: String): Int = {
        @annotation.tailrec
        def rx(index: Int, res: Long): (Int, Long) = {
            if (index + 1 < s.length && s(index) == s(index + 1)) then rx(index + 1, res + 1) else (index + 1, res + 1)
        }
        s.foldLeft((0, 0L)) { case ((i, ans), _) =>
            if(i < s.length) then {
                val (newIndex, count) = rx(i, 0)
                (newIndex, (ans + (count * (count + 1)) / 2) % 1_000_000_007)
            } else {
                (s.length, ans)
            }
        }.last.toInt
    }
}

