



object Solution {
    def retrieveInput(): Array[(Long, Long)] = {
        val text = scala.io.Source.fromFile("input").mkString
        text.replace("\n", "").split(',').map(e => {
            val Array(left, right) = e.split('-')
            val half = left.slice(0, left.length >> 1)
            (left.toLong, right.toLong)
        }).toArray
    }

    def isValid(n: Long): Boolean = {
        val s = n.toString
        val f = s.length >> 1
        s.slice(0, f).repeat(2) == s
    }

    def isAnyValid(n: Long): Boolean = { // inefficient (but does the job)
        val s = n.toString
        val f = s.length - 1
        (1 to f).map(count => s.take(count).repeat(s.length / count)).filter(_.length == f + 1).exists(_ == s)
    }

    def one(): Unit = {
        val res = retrieveInput().map((lo, hi) => (lo to hi).filter(isValid).sum).sum
        println(s"res: $res, ${res == 5398419778L} ")
    }

    def two(): Unit = {
        val res = retrieveInput().map((lo, hi) => (lo to hi).filter(isAnyValid).sum).sum
        println(s"res: $res, ${res == 15704845910L}")
    }

    def main(args: Array[String]): Unit = {
        one()
        two()
    }
}
