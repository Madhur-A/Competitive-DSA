



object Solver {
    def minimumDistance(source: String, dest: String, moves: Array[Array[Int]]): Int = {
        val n = source.length

        val  asInt = (s: String) => Integer.parseInt(s, 2)
        val  start = asInt(source)
        val target = asInt(dest)

        val moveMasks = moves.map(move => move.foldLeft(0)((mask, i) => mask ^ (1 << (n - 1 - i))))
        val t = scala.collection.mutable.Queue[Int]()
        val dist = Array.fill(1 << n)(-1)

        t.enqueue(start)
        dist(start) = 0

        while (t.nonEmpty) {
            val curr = t.dequeue()
            if (curr == target) { return dist(curr) }
            for (mask <- moveMasks) {
                val next = curr ^ mask
                if (dist(next) == -1) {
                    dist(next) = dist(curr) + 1
                    t.enqueue(next)
                }
            }
        }

        return -1 // unreachable
    }

    def minimumDistance(dest: Array[Int], buttons: Array[Array[Int]]): Long = {
        // normal bfs or dfs (even with memoization) fail due to extensiveness of solution space,
        // therefore a curtailment of solution space is used. conceptually, the problem can be
        // viewed as finding non-negative integer solutions to a system of linear equations,
        // where each button contributes a fixed vector and the objective is to minimize the cost
        // (total number of moves). while integer linear solving is feasible, implementing it
        // directly would be verbose and heavy.
        //
        // instead, this solution adopts a parity-based binary decomposition strategy is from
        // `https://www.reddit.com/r/adventofcode/comments/1pk87hl/2025_day_10_part_2_bifurcate_your_way_to_victory/`
        // which shows how to reduce the search by treating each vector coordinate’s parity modulo 2,
        // exploring all subsets of buttons that match the current parity, subtracting their effect,
        // and then halving the remaining vector for recursion. this corresponds to extracting one
        // binary digit at a time from each coordinate of the minimal solution, effectively performing
        // a base-2 digit dynamic programming over the linear system. the recursion depth becomes
        // O(log max(dest)) (for a single test case), and optimality is preserved with memoization.

        val (n, m) = (dest.length, buttons.length)
        val parityMaps = scala.collection.mutable.Map[Vector[Int], scala.collection.mutable.Map[Vector[Int], Int]]()
        val maxMask = 1 << m

        for (mask <- 0 until maxMask) {
            val included = Array.fill(n)(0)
            var freq = 0
            for (j <- 0 until m) {
                if (((mask >> j) & 1) == 1) {
                    freq += 1
                    buttons(j).foreach(button => included(button) += 1);
                }
            }
            val incVector = included.toVector;
            val parVector = included.map(e => e & 1).toVector

            val found = parityMaps.getOrElseUpdate(parVector, scala.collection.mutable.Map.empty)

            found(incVector) = found.get(incVector) match {
                case Some(prev) => math.min(prev, freq)
                case None       => freq
            }
        }

        val seen = scala.collection.mutable.Map[Vector[Int], Option[Long]]()

        def dfs(curr: Vector[Int]): Option[Long] = seen.get(curr) match {
            case Some(res) => res
            case      None => seen(curr) = curr match {
                case curr if (curr.forall(_ == 0)) => Some(0L)
                case curr if (curr.exists(_  < 0)) => None
                case _                             => {
                    val parity = curr.map(_ & 1)
                    parityMaps.get(parity).flatMap { findings =>
                        findings.foldLeft(Option.empty[Long]) { case (res, (pattern, flips)) =>
                            pattern.indices.forall(i => pattern(i) <= curr(i)) match {
                                case false => res
                                case  true => {
                                    val next = curr.indices.map(i => (curr(i) - pattern(i)) >> 1).toVector
                                    dfs(next) match {
                                        case      None => res
                                        case Some(sub) => {
                                            val total = flips.toLong + (sub << 1)
                                            res.fold(Some(total))(e => Some(math.min(e, total)))
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }; seen(curr)
        }

        return dfs(dest.toVector).getOrElse(-1)
    }
}

object Solution {
    def retrieveInput(): Array[String] = {
        val text = scala.io.Source.fromFile("input").mkString.split('\n')
        text
    }

    def one(): Unit = {
        val inputString = retrieveInput()

        var res = 0
        for (line <- inputString) {
            val destPattern = "\\[.+?\\]".r
            val dest =
                destPattern
                    .findFirstMatchIn(line)
                    .get.group(0).replace("[", "").replace("]", "")
                    .map(e => if (e == '.') then '0' else '1')

            val source = dest.map(_ => '0')

            val buttonPattern = "\\s.+?\\{".r
            val buttons =
                buttonPattern
                    .findFirstMatchIn(line)
                    .get.group(0).init.trim
                    .replace("(", "").replace(")", "").split(" ")
                    .map(e => e.split(",").map(_.toInt))

            res += Solver.minimumDistance(source, dest, buttons)
        }

        println(s"res: $res, ${res == 7 || res == 466}")
    }

    def two(): Unit = {
        val inputString = retrieveInput()

        var res = 0L
        for (line <- inputString) {
            val destPattern = "\\{.+?\\}".r
            val dest =
                destPattern
                    .findFirstMatchIn(line).get.group(0)
                    .replace("{", "").replace("}", "").split(",")
                    .map(_.toInt)

            val buttonPattern = "\\s.+?\\{".r
            val buttons =
                buttonPattern
                    .findFirstMatchIn(line).get.group(0).init.trim
                    .replace("(", "").replace(")", "").split(" ")
                    .map(e => e.split(",").map(_.toInt).toArray).toArray

            res += Solver.minimumDistance(dest, buttons);
        }

        println(s"res: $res, ${res == 33 || res == 17214}")
    }

    def main(args: Array[String]): Unit = {
        one()
        two()
    }
}
