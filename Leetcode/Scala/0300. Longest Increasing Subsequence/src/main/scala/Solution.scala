



// certainly NOT functional

// first version
import scala.collection.mutable.ArrayBuffer

object Solution {
    def find_left[A](iterable: Iterable[A], target: A)(implicit ord: Ordering[A]): Int = {
        @annotation.tailrec
        def rx(left: Int, right: Int): Int = (right <= left) match {
            case  true => left
            case false =>  {
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
            (res.last < num) match {
                case  true => res += num
                case false => res(find_left(res, num)) = num
            }; res
        }.length
    }
}


// second version
object Solution {
    def lengthOfLIS(nums: Array[Int]): Int = {
        nums.indices.drop(1).foldLeft(Array.fill(nums.length)(1)) { case (dp, index) =>
            dp.update(index, Math.max(dp(index), {
                dp.take(index).indices.foldLeft(0) { case (innerMax, j) =>
                    (nums(index) <= nums(j)) match {
                        case  true => innerMax
                        case false => math.max(innerMax, dp(j) + 1)
                    }
                }
            })); dp
        }.max
    }
}
