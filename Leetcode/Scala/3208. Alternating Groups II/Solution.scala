






object Solution {
    def numberOfAlternatingGroups(colors: Array[Int], k: Int): Int = {
        val n: Int = colors.length
        (0 until n + k - 2).foldLeft((1, 0)) {
            case((count, ans), index) =>
            val newCount = if(colors(index % n) == colors((n + index - 1) % n)) 1 else count + 1
            (newCount, ans + (if(newCount >= k) 1 else 0))
        }._2
    }
}
