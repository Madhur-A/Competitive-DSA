



object Solution {
    def minimumMountainRemovals(nums: Array[Int]): Int = {
        val n  = nums.length
        def findLeft(numbers: Array[Int], target: Int): Int = {
            def rx(left: Int, right: Int): Int = left < right match {
                case  true => {
                    val mid = left + ((right - left) >> 1)
                    numbers(mid) < target match {
                        case  true => rx(mid + 1, right)
                        case false => rx(left, mid)
                    }
                }
                case false => left
            }
            rx(0, numbers.length)
        }

        def lisForward(index: Int, curr: Array[Int], res: Array[Int]): Array[Int] = index < n match {
            case  true => curr.nonEmpty && nums(index) <= curr.last match {
                case  true => {
                    val insertionIndex = findLeft(curr, nums(index))
                    curr(insertionIndex) = nums(index)
                    res(index) = insertionIndex + 1
                    lisForward(index + 1, curr, res)
                }
                case false => {
                    res(index) = curr.length + 1
                    lisForward(index + 1, curr :+ nums(index), res)
                }
            }
            case false => res
        }

        def lisReverse(index: Int, curr: Array[Int], res: Array[Int]): Array[Int] = index > -1 match {
            case  true => curr.nonEmpty && nums(index) <= curr.last match {
                case  true => {
                    val insertionIndex = findLeft(curr, nums(index))
                    curr(insertionIndex) = nums(index)
                    res(index) = insertionIndex + 1
                    lisReverse(index - 1, curr, res)
                }
                case false => {
                    res(index) = curr.length + 1
                    lisReverse(index - 1, curr :+ nums(index), res)
                }
            }
            case false => res
        }

        val forward = lisForward(0, Array[Int](), Array.fill(n)(0))
        val reverse = lisReverse(n - 1, Array[Int](), Array.fill(n)(0))

        def solve(index: Int, res: Int = Int.MaxValue): Int = index < n match {
            case  true => {
                val (f, b) = (forward(index), reverse(index))
                (f, b) match {
                    case (f, b) if (f > 1 && b > 1) => solve(index + 1, math.min(res, n - f - b + 1))
                    case                         _  => solve(index + 1, res)
                }
            }
            case false => res
        }

        solve(0)
    }
}
