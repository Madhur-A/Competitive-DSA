



// For a query of type 1, queries[i] = [1, l, r]. xor the values with 1 in nums1 from index l to index r. Both l and r are 0-indexed.
// For a query of type 2, queries[i] = [2, p, 0]. For every index 0 <= i < n, set nums2[i] = nums2[i] + nums1[i] * p.
// For a query of type 3, queries[i] = [3, 0, 0]. Find the sum of the elements in nums2.
// Return an array containing all the answers to the third type queries.

object Solution {
    def updateWithXor(index: Int, nums: Array[Long]): Unit = {
        val n = nums.length
        var i = index
        while (i < n) {
            nums(i) = nums(i) ^ 1
            i = i + (i & (-i))
        }
    }

    def updateSecond(index: Int, p: Int, numsOne: Array[Long], numsTwo: Array[Long]): Unit = {
        val n = numsOne.length
        var i = index
        while (i < n) {
            numsTwo(i) = numsTwo(i) + numsOne(i) * p
            i = i + (i & (-i))
        }
    }

    def plusAll(numsOne: Array[Long], numsTwo: Array[Long], p: Int): Unit = {
        for (index <- 1 until numsTwo.length) { updateSecond(index, p, numsOne, numsTwo) }
    }

    def xorSinceTill(nums: Array[Long], since: Int, till: Int): Unit = {
        for (index <- since to till) { updateWithXor(index, nums) }
    }

    def resNumsTwo(numsTwo: Array[Long]): Long = {
        var (i, res) = (numsTwo.length - 1, 0L)
        while (i > 0) {
            res = res + numsTwo(i)
            i = i - (i & (-i))
        }
        res
    }

    def handleQuery(nums1: Array[Int], nums2: Array[Int], queries: Array[Array[Int]]): Array[Long] = {
        val numsOne: Array[Long] = Array(0L) ++ nums1.map(_.toLong)
        val numsTwo: Array[Long] = Array(0L) ++ nums2.map(_.toLong)
        val res = scala.collection.mutable.ArrayBuffer[Long]()
        queries.foreach { query =>
            val Array(queryType, left, right) = query
            queryType match {
                case 1 => xorSinceTill(numsOne, left, right);
                case 2 => plusAll(numsOne, numsTwo, left);
                case _ => res.addOne(resNumsTwo(numsTwo))
            }
        }
        res.toArray
    }

    def main(args: Array[String]) = {
        val nums1 = Array(1) //1,0,1)
        val nums2 = Array(5) //0,0,0)
        val queries = Array(Array(2,0,0),Array(3,0,0)) //Array(1,1,1),Array(2,1,0),Array(3,0,0))

        println(handleQuery(nums1, nums2, queries).mkString("[", ",", "]"))
    }
}
