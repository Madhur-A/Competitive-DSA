



object Solution {
    def canChange(start: String, target: String): Boolean = {
        val s = start.zipWithIndex.filter((char, _) => char != '_')
        val t = target.zipWithIndex.filter((char, _) => char != '_')

        def rx(s: IndexedSeq[(Char, Int)], t: IndexedSeq[(Char, Int)]): Boolean = (s.isEmpty && t.isEmpty) match {
            case  true => true
            case false => s.head.head == t.head.head match {
                case false => false
                case  true => {
                    val (x, y, z) = (s.head.head, s.head.last, t.head.last)
                    (x, y, z) match {
                        case (x, y, z) if x == 'L' && y < z => false
                        case (x, y, z) if x == 'R' && y > z => false
                        case                              _ => rx(s.tail, t.tail)
                    }
                }
            }
        }

        s.length == t.length match {
            case  true => rx(s, t)
            case false => false
        }
    }
}
