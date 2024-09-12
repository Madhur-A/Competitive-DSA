



import scala.util.control.Breaks._

// there're problems which designed for a very specific type of solution;
// i'm really not a fan of such problems.

// such problems hinge on edge cases created by eccentric features of 
// a specific language and are devoid of any logic; this is one such problem

object Solution {
    def recoverArray(nums: Array[Int]): Array[Int] = {
        val sortedNums = nums.sorted
        val n = sortedNums.length

        def check(nums: Array[Int], k: Int, seen: scala.collection.mutable.Map[Int, Int]): (Boolean, Array[Int]) = {
            var (state, res) = (true, scala.collection.mutable.ArrayBuffer[Int]())
            breakable {
                for (num <- nums) {
                    if (seen.getOrElse(num, 0) > 0) {
                        if (seen.getOrElse(num + k, 0) > 0) {
                            seen.update(num, seen.getOrElse(num, 0) - 1)
                            seen.update(num + k, seen.getOrElse(num + k, 0) - 1)
                            res :+= num + k / 2
                        } else { state = false; res.clear; break; }
                    }
                }
            }
            (state, res.toArray)
        }

        val seen = scala.collection.mutable.Map.empty[Int, Int] ++ sortedNums.groupBy(identity).view.mapValues(_.length)
        val res = scala.collection.mutable.ArrayBuffer[Int]()
        breakable {
            for (i <- 1 until n) {
                val k = sortedNums(i) - sortedNums(0)
                if (k != 0 && k % 2 == 0) {
                    val (a, b) = check(sortedNums, k, seen.clone)
                    if (a) { res.appendAll(b); break }
                }
            }
        }
        res.toArray
    }
}
