



object Solution {
    def countVowels(s: String): Long = {
        val (n, vowels) = (s.length, "aeiou".toSet)
        s.zipWithIndex.foldLeft(0L) { case (res, (char, index)) =>
            (vowels.contains(char)) match {
                case false => res
                case  true => res + ((n - index) * 1L * (index + 1))
            }
        }
    }
}
