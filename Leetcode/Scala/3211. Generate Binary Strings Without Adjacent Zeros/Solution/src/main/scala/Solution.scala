



object Solution {
    def validStrings(n: Int, res: List[String] = List[String]()): List[String] = n match {
        case 0 => res
        case _ => res match {
            case Nil => {
                validStrings(n - 1,  List("1")) ::: validStrings(n - 1, List("0"))
            }
            case   _ => {
                res.head.head match {
                    case '0' => validStrings(n - 1, ("1" ++ res.head :: res.drop(1)))
                    case  _  => validStrings(n - 1, ("1" ++ res.head :: res.drop(1))) ::: validStrings(n - 1, ("0" ++ res.head :: res.drop(1)))
                }
            }
        }
    }
}
