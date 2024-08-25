



object Solution {
     def power(n: Int, res: Long): Long = if (n == 0) res else power(n - 1, 10L * res)

     def reverseNumber(num: Long): Long = num.toString.reverse.toLong

     def getKthPalindrome(len: Int, k: Long): Long = {
         val mid = if (len % 2 == 0) then len/2 - 1 else len/2
         val (left, right) = (power(mid, 1L), power(mid + 1, 1L))
         val (base, suffx) = if (len % 2 == 1) then (left, 10) else (right, 1)

         val number = left + k - 1
         if (k <= right - left) then base * number + reverseNumber(number / suffx) else -1
     }

     def kthPalindrome(queries: Array[Int], intLength: Int): Array[Long] = {
         queries.indices.foldLeft(Array.fill(queries.length)(0L)) { case (res, index) =>
             res.update(index, getKthPalindrome(intLength, queries(index))); res
         }
     }
}
