



object Fib {
    def multiply(F: Array[Array[BigInt]], M: Array[Array[BigInt]]): Array[Array[BigInt]] = {
        val x = F(0)(0) * M(0)(0) + F(0)(1) * M(1)(0)
        val y = F(0)(0) * M(0)(1) + F(0)(1) * M(1)(1)
        val z = F(1)(0) * M(0)(0) + F(1)(1) * M(1)(0)
        val w = F(1)(0) * M(0)(1) + F(1)(1) * M(1)(1)

        Array(Array(x, y), Array(z, w))
    }

    def power(M: Array[Array[BigInt]], n: Int): Array[Array[BigInt]] = (n == 0 || n == 1) match {
        case  true => M
        case false => {
            val halfPow = power(M, n / 2)
            val  result = multiply(halfPow, halfPow)
            (n & 1) match {
                case 1 => multiply(result, M)
                case _ => result
            }
        }
    }

    def fib(n: Int): BigInt = n < 0 match {
        case  true => if ((n & 1) == 1) fib(-n) else -fib(-n)
        case false => (n < 2) match {
            case  true => n
            case false => {
                val M = Array(Array(BigInt(1), BigInt(1)), Array(BigInt(1), BigInt(0)))
                power(M, n - 1)(0)(0)
            }
        }
    }
}
