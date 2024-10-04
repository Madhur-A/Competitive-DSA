



object Solution {
    val  factors = scala.collection.mutable.Map[Long, List[Long]](1L -> List(1L))
    val divisors = scala.collection.mutable.Map[Long, Long](1L -> 1L)

    def primeFactors(num: Long, k: Long = 2L): List[Long] = factors.contains(num) match {
        case true  => factors(num)
        case false => {
            num match {
                case                   1L => List(1L)
                case num if (num < k * k) => factors(num) = List(1L, num); factors(num)
                case                  num => {
                    num % k match {
                        case 0L => factors(num) = List(k) ::: primeFactors(num / k); factors(num)
                        case  _ => primeFactors(num, k + 1)
                    }
                }
            }
        }
    }

    val aux: ((Long, Int)) => Long = (e) => e._2 + 1 // for scala 2.11.x

    def numberOfDivisors(num: Long): Long = divisors.contains(num) match {
        case true  => divisors(num)
        case false => {
            divisors(num) =
                primeFactors(num).sorted.tail.groupBy(identity).mapValues(_.size).map(aux).toList.foldLeft(1L)(_ * _)
                // primeFactors(num).sorted.tail.groupBy(identity).view.mapValues(_.size).map((key, value) => value + 1).toList.foldLeft(1L)(_ * _)
            divisors(num)
        }
    }

    def f(x: Long, d: Long): Long = d match {
        case 1L => numberOfDivisors(x)
        case  _ => 1 + f(x, d - 1) + numberOfDivisors(x)
    }

    def main(args: Array[String]) = {
        val reader = scala.io.StdIn
        val  cases = reader.readInt
        for (_ <- 1 to cases) {
            val line = reader.readLine.split(" ").map(_.toLong)
            val (n, k, d) = (line(0), line(1), line(2))
            var res: Long = 0L
            for(i <- 1L to n) {
                res += f(math.pow(i, k).toLong, d)
                res %= 1000000007L
            }
            println(s"$res")
        }
    }
}
