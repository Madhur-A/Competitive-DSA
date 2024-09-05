



object Solution {
    def missingRolls(rolls: Array[Int], mean: Int, n: Int): Array[Int] = {
        val needed = (n + rolls.length) * mean - rolls.sum
        if (n <= needed && needed <= 6*n) {
            Array.tabulate(n)(element => (needed / n) + (if (element < (needed % n)) 1 else 0))
        } else { Array.empty }
    }
}
