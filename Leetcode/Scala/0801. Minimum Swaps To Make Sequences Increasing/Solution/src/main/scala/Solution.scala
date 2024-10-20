



object Solution {
    def minSwap(nums1: Array[Int], nums2: Array[Int], reverse: Boolean = false): Int = reverse match {
        case false => minSwap(nums1.reverse, nums2.reverse, true)
        case  true => {
            val (a, b, n) = (nums1.head, nums2.head, nums1.length)
            val dp = Array.fill(n, 2)(-1)
            def rx(a: Int = Int.MaxValue, b: Int = Int.MaxValue, index: Int = 0, swapped: Int = 0): Int = (index < n) match {
                case false => 0
                case  true => {
                    (dp(index)(swapped) == -1) match {
                        case false => dp(index)(swapped)
                        case  true => {
                            val     asBefore = ((nums1(index) < a) && (nums2(index) < b))
                            val swapPossible = (asBefore && nums1(index) < b && nums2(index) < a)
                            dp(index)(swapped) = (asBefore) match {
                                case  true => swapPossible match {
                                    case  true => math.min(rx(nums1(index), nums2(index), index + 1, 0), 1 + rx(nums2(index), nums1(index), index + 1, 1))
                                    case false => rx(nums1(index), nums2(index), index + 1, 0)
                                }
                                case false => 1 + rx(nums2(index), nums1(index), index + 1, 1)
                            }
                            dp(index)(swapped)
                        }
                    }
                }
            }
            rx()
        }
    }

    def main(args: Array[String]): Unit = {
        val (nums1, nums2) = (Array(1,3,5,4), Array(1,2,3,7)) //(Array(0,4,4,5,9), Array(0,1,6,8,10))
        val res = minSwap(nums1, nums2)
        println(s"result is $res")
    }
}
