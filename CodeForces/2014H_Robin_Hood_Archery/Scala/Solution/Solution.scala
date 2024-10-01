



object Solution {
    def main(args: Array[String]): Unit = {
        val reader = scala.io.StdIn
        val t = reader.readLine.toInt
        for (cases <- 1 to t) {
            val Array(n, q) = reader.readLine.split(" ").map(_.toInt)
            val target = reader.readLine.split(" ").map(_.toInt)
            val randomStream = Stream.continually((math.random * 10000000).toInt).distinct
            val mappings = target.distinct.zip(randomStream).toMap

            val prefixT = target.scanLeft(0)(_ ^ _)
            val prefixS = target.map(mappings).toArray.scanLeft(0)(_ ^ _)
            for (queries <- 1 to q) {
                val Array(left, right) = reader.readLine.split(" ").map(_.toInt)
                val first = prefixT(left - 1) ^ prefixT(right)
                val second = prefixS(left - 1) ^ prefixS(right)
                val res = (first == 0) && (second == 0)
                println(if (res) "YES" else "NO")
            }
        }
    }
}
