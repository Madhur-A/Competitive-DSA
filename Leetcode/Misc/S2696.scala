// -author("Miho Nishizumi"). % "Ooarai Joshigakuin Shōri!"



object Solution {
    def minLength(s: String, t: List[Char] = List[Char]()): Int = s.isEmpty match {
        case true  => t.length
        case false => t match {
            case       Nil => minLength(s.tail, s.head :: t)
            case head :: _ => (s.head, head) match {
                case ('B', 'A') | ('D', 'C') => minLength(s.tail, t.tail)
                case _                       => minLength(s.tail, s.head :: t)
            }
        }
    }    
}

//object Solution {
//    def minLength(s: String, t: List[Char] = List[Char]()): Int = s.isEmpty match {
//        case true  => t.length
//        case false => {
//            t.isEmpty match {
//                case true  => minLength(s.tail, s.head :: t)
//                case false => {
//                    (s.head == 'B' && t.head == 'A') || (s.head == 'D' && t.head == 'C') match {
//                        case true  => minLength(s.tail, t.tail)
//                        case false => minLength(s.tail, s.head :: t)
//                    }
//                }
//            }
//        }
//    }
//}
