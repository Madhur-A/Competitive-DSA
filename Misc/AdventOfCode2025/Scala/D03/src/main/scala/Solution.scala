



object Solution {
    def retrieveInput(): Array[String] = {
        val text = scala.io.Source.fromFile("input").mkString
        text.split('\n').toArray
    }

    def maxPossibleNum(nums: Array[Int], len: Int): Long = {
        val t = scala.collection.mutable.ArrayBuffer[Int]()
        var toRemove = nums.length - len

        for (num <- nums) {
            while (t.nonEmpty && toRemove > 0 && t.last < num) {
                t.remove(t.length - 1)
                toRemove -= 1
            }
            t.append(num)
        }

        t.take(len).map(e => (e + '0').toChar).mkString.toLong
    }

    def one(): Unit = {
        val res = retrieveInput().map(e => maxPossibleNum(e.toArray.map(_ - '0'), 2)).sum
        println(s"res: $res, ${res == 17074L}")
    }

    def two(): Unit = {
        val res = retrieveInput().map(e => maxPossibleNum(e.toArray.map(_ - '0'), 12)).sum
        println(s"res: $res, ${res == 169512729575727L}")
    }

    def main(args: Array[String]): Unit = {
        one()
        two()
    }
}
