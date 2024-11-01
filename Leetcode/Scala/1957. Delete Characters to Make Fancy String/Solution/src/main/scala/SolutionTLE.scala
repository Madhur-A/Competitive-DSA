



object SolutionTLE {
    def makeFancyString(s: String): String = {
        def rx(s: String, a: Char, b: Char, res: List[Char]): List[Char] = s.isEmpty match {
            case false => a == b && s.head == a match {
                case false => rx(s.tail, s.head, a, s.head :: res)
                case  true => rx(s.tail, s.head, a, res)
            }
            case  true => res
        }
        rx(s, '1', '0', List[Char]()).reverse.mkString
    }
}
