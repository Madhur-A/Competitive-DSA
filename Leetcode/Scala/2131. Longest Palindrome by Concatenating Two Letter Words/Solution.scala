



object Solution {
    def longestPalindrome(words: Array[String]): Int = {
        val g = words.groupBy(identity).view.mapValues(_.size)
        g.foldLeft((0, 0)) { case((pCount, res), (word, freq)) =>
            val rWord = word.reverse
            if(word(0) == word(1)) {
                (pCount | (freq & 1), res + (freq/2)* 4)
            } else if(g.contains(rWord)) {
                (pCount, res + math.min(freq, g(rWord)) * 2)
            } else { (pCount, res) }
        } match {
            case(pCount, res) => res + (2 * pCount)
        }
    }
}
