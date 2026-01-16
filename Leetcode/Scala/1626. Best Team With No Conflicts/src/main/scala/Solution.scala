




object Solution {
    // naturally one would do this
    def bestTeamScore(scores: Array[Int], ages: Array[Int]): Int = {
        val players = scores.zip(ages).sorted
        players.zipWithIndex.foldLeft(Array.fill(players.length)(0)) { case (dp, ((score, age), i)) =>
            dp(i) = score
            players.take(i).zipWithIndex.foldLeft(dp) { case (dp, ((_, ageI), j)) =>
                if (ageI <= age) { dp(i) = Math.max(dp(i), dp(j) + score) }; dp
            }; dp
        }.max
    }

    // the follwing novelty uses Fenwick; and is by someone whose
    // name i don't know. nevertheless super solution!
    def bestTeamScoreFenwick(scores: Array[Int], ages: Array[Int]): Int = {
        val players = ages.zip(scores).sorted
        val points  = scores.toSet.toVector.sorted

        val fenwick = Array.fill(points.length + 1)(0)

        players.foldLeft(0) { case (res, (_, score)) =>
            val found = points.indexOf(score) + 1
            var (i, curr) = (found, 0)
            while (i > 0) {
                curr = Math.max(curr, fenwick(i))
                i -= i & -i;
            }

            var j = found
            while (j <= points.length) {
                fenwick(j) = Math.max(fenwick(j), curr + score)
                j += j & -j;
            }

            Math.max(res, curr + score)
        }
    }

    def main(args: Array[String]): Unit = {
        println(s"res: ${bestTeamScoreFenwick(Array(1, 3, 5, 10, 15), Array(1, 2, 3, 4, 5))}");
        println(">>>>>>>>>>>>>>>>>>>>>>> compiled successfully!");
    }
}
