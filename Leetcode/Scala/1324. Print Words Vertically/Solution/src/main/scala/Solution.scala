



object Solution {
    def paddedArray(nums: Array[Char], k: Int): Array[Char] = (nums.length == k) match {
        case false => nums ++ Array.fill(k - nums.length)(' ')
        case  true => nums
    }

    def stripLast(s: String): String = (s.head == ' ') match {
        case false => s.reverse
        case  true => stripLast(s.tail)
    }

    def printVertically(s: String): List[String] = {
        val words = s.split(" ")
        val maxLn = words.maxBy(_.length).length
        words.map(e => paddedArray(e.toArray, maxLn)).transpose.map(f => stripLast(f.mkString.reverse)).toList
    }
}
