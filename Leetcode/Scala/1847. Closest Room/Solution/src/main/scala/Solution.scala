



// ::highly non functional::
// apparently constraints of this problem
// have aversion to methods like .filter .map etc

class Solve(rooms: Array[Array[Int]]) {
    val n = rooms.length
    val sortedRooms = rooms.sortBy(_(1))

    def findClosest(target: Int): Int = {
        def rx(left: Int, right: Int): Int = (left < right) match {
            case  true => {
                val mid = left + ((right - left) >> 1)
                sortedRooms(mid)(1) match {
                    case x if (x < target) => rx(mid + 1, right)
                    case x                 => rx(left, mid)
                }
            }
            case false => left
        }
        rx(0, n)
    }
}

object Solve {
    def apply(rooms: Array[Array[Int]], queries: Array[Array[Int]]): Array[Int] = {
        val sol = new Solve(rooms)
        val res = Array.fill(queries.length)(-1)

        queries.zipWithIndex.foreach((query, qIndex) => {
            val Array(preferred, minSize) = query
            val closestRoomIndex = sol.findClosest(minSize)
            var minimumDifference = Int.MaxValue
            var minimumPossibleRoom = Int.MaxValue

            (closestRoomIndex until sol.n).foreach(e => {
                val diff = math.abs(preferred - sol.sortedRooms(e)(0))
                if (diff <= minimumDifference) {
                    if (diff == minimumDifference) {
                        minimumPossibleRoom = math.min(minimumPossibleRoom, sol.sortedRooms(e)(0))
                    } else {
                        minimumPossibleRoom = sol.sortedRooms(e)(0)
                        minimumDifference = diff
                    }
                }
            })

            if (minimumPossibleRoom != Int.MaxValue) {
                res(qIndex) = minimumPossibleRoom
            }

            // var ids = sortedRooms.filter(_(1) >= minSize).map(_(0)).toArray // this gives MLE
        })
        res
    }
}

object Solution {
    def closestRoom(rooms: Array[Array[Int]], queries: Array[Array[Int]]): Array[Int] = Solve(rooms, queries)
}
