



object Solution {
    def numberOfSubstrings(s: String): Int = {
        def rx(s: String, a: Int = -1, b: Int = -1, c: Int = -1, index: Int = 0, res: Int = 0): Int = s.isEmpty match {
            case false => {
                rx(s.tail,
                   if (s.head == 'a') index else a,
                   if (s.head == 'b') index else b,
                   if (s.head == 'c') index else c,
                   index + 1,
                   res + 1 + (math.min(a, math.min(b, c))))
            }
            case  true => res + math.min(a, math.min(b, c)) + 1
        }
        rx(s)
    }
}
