



object Solution {
    def diffWaysToCompute(expression: String): List[Int] = expression.forall(Character.isDigit) match {
        case false => expression.zipWithIndex.flatMap { case (char, index) =>
            ("+-*".contains(char)) match {
                case  true => {
                    val (left, right) = expression.splitAt(index)
                    val lEval = diffWaysToCompute(left)
                    val rEval = diffWaysToCompute(right.tail)
                    for {
                        lElem <- lEval
                        rElem <- rEval
                    } yield char match {
                        case '-' => lElem - rElem
                        case '*' => lElem * rElem
                        case '+' => lElem + rElem
                    }
                }
                case false => Nil
            }
        }.toList
        case  true => List(expression.toInt)
    }
}
