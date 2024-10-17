



object Solution {
    def maxTurbulenceSize(nums: Array[Int]): Int = (nums.length < 2) match {
        case  true => nums.length;
        case false => {
            def rx(index: Int, prevComp: Int, prevLen: Int, res: Int): Int = (index < nums.length) match {
                case  true => {
                    val currComp = nums(index).compare(nums(index - 1))
                    val (newComp, newLen) = (currComp, prevComp) match {
                            case (0, _)                   => (currComp, 1)
                            case (`prevComp`, `prevComp`) => (currComp, 2)
                            case _                        => (currComp, prevLen + 1)
                        }
                    rx(index + 1, newComp, newLen, math.max(res, newLen))
                }
                case false => res
            }
            rx(1, 0, 1, 1);
        }
    }
}
