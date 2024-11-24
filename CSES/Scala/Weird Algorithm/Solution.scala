



object Solution {
    def main(args: Array[String]): Unit = {
        val n = scala.io.StdIn.readLong
        def rx(n: Long): Unit = n match {
            case 1L => println("1")
            case  _ => {
                print(s"$n ")
                (n & 1L) match {
                    case 1L => rx(3L * n + 1L)
                    case  _ => rx(n / 2L)
                }
            }
        }
        rx(n)
    }
}
