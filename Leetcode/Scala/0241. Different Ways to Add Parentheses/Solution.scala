



// with "local mutation" combined with imperative "if-else" construct
// though still largely functional
object Solution {
    def diffWaysToCompute(expression: String): List[Int] = {
        if (!expression.forall(Character.isDigit)) {
            expression.zipWithIndex.foldLeft(List[Int]()) { case (res, (char, index)) =>
                if ("+-*".contains(char)) {
                    val (left, right) = expression.splitAt(index)
                    val lEval = diffWaysToCompute(left)
                    val rEval = diffWaysToCompute(right.tail)
                    lEval.foldLeft((res, rEval)) { case ((res, rEval), lElem) =>
                        (rEval.foldLeft(res) { case(res, rElem) =>
                            if (char == '-') {
                                (lElem - rElem) :: res
                            } else if (char == '*') {
                                (lElem * rElem) :: res
                            } else {
                                (lElem + rElem) :: res
                            }
                        }, rEval)
                    }.head
                } else { res }
            }
        } else { List(expression.toInt) }
    }
}


// strictly functional version
object Solution {
    def diffWaysToCompute(expression: String): List[Int] = {
        if (!expression.forall(Character.isDigit)) {
            expression.zipWithIndex.flatMap { case (char, index) =>
                if ("+-*".contains(char)) {
                    val (left, right) = expression.splitAt(index)
                    val lEval = diffWaysToCompute(left)
                    val rEval = diffWaysToCompute(right.tail)
                    for {
                        lElem <- lEval
                        rElem <- rEval
                    } yield {
                        char match {
                            case '-' => lElem - rElem
                            case '*' => lElem * rElem
                            case '+' => lElem + rElem
                        }
                    }
                } else { Nil }
            }.toList
        } else { List(expression.toInt) }
    }
}
