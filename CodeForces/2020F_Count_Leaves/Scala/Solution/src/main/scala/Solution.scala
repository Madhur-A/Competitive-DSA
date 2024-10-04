



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

    def numberOfDivisors(num: Long): Long = divisors.contains(num) match {
        case true  => divisors(num)
        case false => {
            divisors(num) =
                // this collapses in Scala 2.11.x (and perhaps 2.12.x too!).
                primeFactors(num).sorted.tail.groupBy(identity).view.mapValues(_.size).map((key, value) => value + 1).toList.foldLeft(1L)(_ * _)
            // therefore for older versions
            // primeFactors(num).sorted.tail.groupBy(identity).mapValues(_.size).map(e => e._2 + 1).toList.foldLeft(1L)(_ * _)
            divisors(num)
        }
    }

    def isPrime(num: Long): Boolean = primeFactors(num).length == 2

    def f(x: Long, d: Long): Long = d match {
        case 1L => numberOfDivisors(x)
        case  d => {
            x match {
                case 1L => 1L
                case  _ => if (isPrime(x)) 1 + f(x, d - 1) else 1 + f(x, d - 1) + numberOfDivisors(x)
            }
        }
    }

    def main(args: Array[String]) = {
        // val reader = scala.source.io.StdIn
        val cases   = 1 //reader.readLine.toInt
        for (_ <- 1 to cases) {
            val (n, k, d) = (10L, 1L, 2L) //reader.readLine.split(" ").map(_.toLong)
            var res: Long = 0L
            for(i <- 1L to n) {
                val x: Long = math.pow(i, k).toDouble.toLong
                println(s"sending f($x, $d)")
                res += f(x, d)
                res %= 1000000007L
            }
            println(s"$res") // veering by +1
        }
    }
}
