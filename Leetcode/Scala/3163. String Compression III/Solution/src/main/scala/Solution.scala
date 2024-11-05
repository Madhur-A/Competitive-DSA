



object Solution {
    def compressedString(word: String): String = {

        val repeatThis: (Int, Char) => String = (n, c) => s"${c}9" * n

        def calculate(n: Int, c: Char): String = (n <= 9) match {
            case false => n % 9 match {
                case 0 => repeatThis(n / 9, c)
                case _ => s"${c}${n % 9}${repeatThis(n / 9, c)}"
            }
            case  true => s"${c}${n}"
        }

        def rx(inputString: String, prev: Char, res: String = ""): String = inputString.isEmpty match {
            case  true => res
            case false => {
                val count = inputString.takeWhile(_ == prev).length
                val newString = inputString.dropWhile(_ == prev)
                val remString = calculate(count, prev)
                newString.isEmpty match {
                    case  true => remString + res
                    case false => rx(newString, newString.head, remString + res)
                }
            }
        }

        rx(word, word.head).reverse
    }
}
