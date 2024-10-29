



// certainly NOT functional

object Solution {
    def tallestBillboard(rods: Array[Int]): Int = {
        val      n = rods.length
        val target = rods.sum >> 1
        val     dp = Array.fill(n, target + 1)(-1)

        val invalid = -5555

        def rx(index: Int, sumLen: Int): Int = (index < n) match {
            case  true => (sumLen > target) match {
                case  true => invalid
                case false => dp(index)(sumLen) match {
                    case -1 => { // first pass
                        val a = rx(index + 1, sumLen) // skip
                        val b = rx(index + 1, sumLen + rods(index)) + rods(index) // pick
                        val c = rx(index + 1, math.abs(sumLen - rods(index))) + math.max(0, rods(index) - sumLen) // diff
                        dp(index)(sumLen) = List(a, b, c).max
                        dp(index)(sumLen)
                    }
                    case  _ => dp(index)(sumLen)
                }
            }
            case false => sumLen match {
                case 0 =>  0
                case _ =>  invalid
            }
        }

        rx(0, 0)
    }
}
