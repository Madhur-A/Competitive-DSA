



object Solution {
    def getLucky(s: String, k: Int): Int = {
        (1 until k).foldLeft(s.map(e => e - 'a' + 1).flatMap(e => Seq(e / 10, e % 10)).sum) { case (ans, _) =>
            ans.toString.map(e => e - '0').sum
        }
    }
}

// using one auxiliary

object Solution {
    def getLucky(s: String, k: Int): Int = {
        val asDigits = (c: Char) => Seq((c - 'a' + 1) / 10, (c - 'a' + 1) % 10)
        (1 until k).foldLeft(s.flatMap(asDigits).sum) { case (ans, _) =>
            ans.toString.map(e => e - '0').sum
        }
    }
}


// using two auxiliaries

object Solution {
    def asSumOfDigits(res: Int, times: Int): Int = res.toString.map(_ - '0').sum
    def getLucky(s: String, k: Int): Int = {
        val inDigits = (c: Char) => Seq((c - 'a' + 1) / 10, (c - 'a' + 1) % 10)
        (1 until k).foldLeft(s.flatMap(inDigits).sum)(asSumOfDigits)
    }
}

// using only auxiliaries

object Solution {
    def asSumOfDigits(res: Int, times: Int): Int = res.toString.map(_ - '0').sum
    def inDigits(inputChar: Char): Seq[Int] = Seq((inputChar - 'a' + 1) / 10, (inputChar - 'a' + 1) % 10)
    def getLucky(s: String, k: Int): Int = (1 until k).foldLeft(s.flatMap(inDigits).sum)(asSumOfDigits)
}

