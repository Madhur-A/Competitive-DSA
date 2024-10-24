



object Solution {
    def racecar(target: Int): Int = {
        (1 to target).foldLeft(Array.fill(target + 1)(0)) { case (dp, index) =>
            val nearest = index.toBinaryString.length
            (index == (1 << nearest) - 1) match {
                case  true => { dp(index) = nearest; dp }
                case false => {
                    dp(index) = dp((1 << nearest) - 1 - index) + nearest + 1
                    for (j <- 0 until nearest) {
                        val remains = (1 << (nearest - 1)) - (1 << j)
                        dp(index) = math.min(dp(index), dp(index - remains) + nearest - 1 + j + 2)
                    }; dp
                }
            }
        }(target)
    }
}
