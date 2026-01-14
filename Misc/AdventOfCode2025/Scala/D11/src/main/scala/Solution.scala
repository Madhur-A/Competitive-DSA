



object Solution {
    def retrieveInput(): Array[String] = {
        val text = scala.io.Source.fromFile("input").mkString.split('\n')
        text
    }

    def one(): Unit = {
        val inputString = retrieveInput()

        val g =
            inputString.map(e => e.split(": "))
                .map(arr => arr.head -> arr.last.trim.split(" ").toSet)
                .toMap
        val seen = scala.collection.mutable.Map[(String,String), Long]()

        // let's go quasi-functional dfs (instead of usual procedural bfs, till now)
        def rxPaths(source: String, dest: String): Long = (source, dest) match {
            case (source, dest) if (seen.contains((source, dest))) => seen.get((source, dest)).get
            case (source, dest) if (source == dest)                => 1L
            case                                                 _ => {
                seen((source, dest)) =
                    g.getOrElse(source, Set.empty).foldLeft(0L) { case (res, child) =>
                        res + rxPaths(child, dest)
                    }
                seen((source, dest))
            }
        }
        val res = rxPaths("you", "out")

        println(s"res: $res, ${res == 5 || res == 539}")
    }

    def two(): Unit = {
        val inputString = retrieveInput()

        val g =
            inputString.map(e => e.split(": "))
                .map(arr => arr.head -> arr.last.trim.split(" ").toSet)
                .toMap
        val seen = scala.collection.mutable.Map[(String,String), Long]()

        // and again .... .
        def rxPaths(source: String, dest: String, excluded: Set[String]): Long = (source, dest) match {
            case (source, dest) if (seen.contains((source, dest))) => seen.get((source, dest)).get
            case (source, dest) if (source == dest)                => 1L
            case                                                 _ => {
                seen((source, dest)) =
                    g.getOrElse(source, Set.empty).foldLeft(0L) { case (res, child) =>
                        excluded.contains(child) match {
                            case  true => res
                            case false => res + rxPaths(child, dest, excluded)
                        }
                    }
                seen((source, dest))
            }
        }

        // because the number of paths from `some_source` to `some_dest`
        // (following some prior mutually exclusive(!!) constraints) would always be same
        val res =
            (rxPaths("svr", "dac", Set("fft", "out")) * rxPaths("dac", "fft", Set("svr", "out")) *
             rxPaths("fft", "out", Set("dac", "svr"))) + /* <- notice */
            (rxPaths("svr", "fft", Set("dac", "out")) * rxPaths("fft", "dac", Set("svr", "out")) *
             rxPaths("dac", "out", Set("svr", "fft")))

        println(s"res: $res, ${res == 2L || res == 413167078187872L}")
    }

    def main(args: Array[String]): Unit = {
        one()
        two()
    }
}
