



object Solution {
    def makeFancyString(s: String): String = {
        s.foldRight((List[Char](), 1, '1')) { case (curr, (res, count, prev)) =>
            val newCount = if (curr == prev) count + 1 else 1
            newCount match {
                case x if (3 <= x) => (res, newCount, curr)
                case            _  => (curr :: res, newCount, curr)
            }
        }.head.mkString
    }
}
