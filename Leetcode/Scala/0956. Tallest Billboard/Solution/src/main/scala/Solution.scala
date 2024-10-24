



// certainly NOT functional

object Solution {
    def tallestBillboard(rods: Array[Int]): Int = {
        val      n = rods.length
        val target = rods.sum / 2
        val     dp = Array.fill(n, target + 1)(-1)

        val invalid = -5555

        def rx(index: Int, cumLen: Int): Int = (index < n) match {
            case  true => (cumLen > target) match {
                case  true => invalid
                case false => dp(index)(cumLen) match {
                    case -1 => { // first pass
                        val a = rx(index + 1, cumLen) // skip
                        val b = rx(index + 1, cumLen + rods(index)) + rods(index) // pick
                        val c = rx(index + 1, math.abs(cumLen - rods(index))) + math.max(0, rods(index) - cumLen) // diff
                        dp(index)(cumLen) = List(a, b, c).max
                        dp(index)(cumLen)
                    }
                    case  _ => dp(index)(cumLen)
                }
            }
            case false => cumLen match {
                case 0 =>  0
                case _ =>  invalid
            }
        }

        rx(0, 0)
    }
}
