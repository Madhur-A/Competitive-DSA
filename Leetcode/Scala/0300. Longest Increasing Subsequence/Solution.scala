




import scala.collection.mutable.ArrayBuffer

object Solution {
    def find_left[A](iterable: Iterable[A], target: A)(implicit ord: Ordering[A]): Int = {
        @annotation.tailrec
        def rx(left: Int, right: Int): Int = {
            if (right <= left) {
                left
            } else {
                val mid = left + ((right - left) >> 1)
                iterable.drop(mid).head match {
                    case found if ord.lt(found, target) => rx(mid + 1, right)
                    case                              _ => rx(left, mid)
                }
            }
        }
        rx(0, iterable.size)
    }
    
    def lengthOfLIS(nums: Array[Int]): Int = {
        val res = ArrayBuffer[Int]()
        res += nums(0)
        nums.tail.foldLeft(res) { case (res, num) => 
            if(res.last < num) {
                res += num
            } else {
                res.update(find_left(res, num), num); res
            }
        }.length
    }
}
