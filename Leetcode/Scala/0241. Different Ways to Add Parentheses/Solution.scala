



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
