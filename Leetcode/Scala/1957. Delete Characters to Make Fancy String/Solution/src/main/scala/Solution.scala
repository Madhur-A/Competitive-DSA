



object Solution {
    def makeFancyString(s: String): String = {
        s.foldLeft((List[Char](), 1, '1')) { case ((res, count, prev), curr) =>
            val newCount = if (curr == prev) count + 1 else 1
            newCount match {
                case x if (3 <= x) => (res, newCount, curr)
                case            _  => (curr :: res, newCount, curr)
            }
        }.head.reverse.mkString
    }
}
