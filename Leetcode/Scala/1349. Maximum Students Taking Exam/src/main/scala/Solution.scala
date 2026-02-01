



object Solution {
    // i'll try to make this functional; though this might get ugly
    def maxStudents(seats: Array[Array[Char]]): Int = {
        val (r, c) = (seats.length, seats(0).length)
        val  total = 1 << c
        val valids =
            seats.map { e =>
                e.zipWithIndex
                    .filter((c, _) => c == '.')
                    .foldLeft(0) { case (acc, (_, j)) =>
                        acc | (1 << j)
                    }
            }

        val hasAdjacent = (seat: Int) => (seat & (seat << 1)) != 0
        val isValidSeat = (seat: Int, j: Int) => (seat & valids(j)) == seat
        val noCrossConn = (left: Int, right: Int) => ((left & (right << 1)) == 0) && ((left & (right >> 1)) == 0)

        val dp =
            (0 until r).foldLeft(Array.fill(total)(-1).updated(0, 0)) { case (dp, i) =>
                (0 until total)
                    .filter(curr => !hasAdjacent(curr) && isValidSeat(curr, i))
                    .foldLeft(Array.fill(total)(-1)) { case (next, curr) =>
                        (0 until total)
                            .filter(prev => (dp(prev) != -1) && noCrossConn(curr, prev))
                            .foreach { prev =>
                                next(curr) = math.max(next(curr), dp(prev) + Integer.bitCount(curr))
                            }; next
                    }
            }

        dp.max
    }

    def main(args: Array[String]): Unit = {
        val  seats =
            Array(
                Array('#','.','#','#','.','#'),
                Array('.','#','#','#','#','.'),
                Array('#','.','#','#','.','#'))

        println(s"res: ${maxStudents(seats)}")

        println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
    }
}
