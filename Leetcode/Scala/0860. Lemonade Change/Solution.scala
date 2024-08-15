







object Solution {
    def lemonadeChange(bills: Array[Int]): Boolean = {
        bills.foldLeft((true, 0, 0)) { case ((res, fives, tens), bill) => 
            if (! res) then {
                (false, fives, tens)
            } else {
                val (newFives, newTens, newRes) = bill match {
                    case  5 => (fives + 1, tens, res)
                    case 10 => if (fives > 0) then (fives - 1, tens + 1, res) else (fives, tens, false)
                    case  _ => if (fives > 0 && tens > 0) then {
                                    (fives - 1, tens - 1, res)
                                } else if (fives > 2) then {
                                    (fives - 3, tens, res)
                                } else {
                                    (fives, tens, false)
                                }
                }
                (newRes, newFives, newTens)
            }
        }.head
    }
}
