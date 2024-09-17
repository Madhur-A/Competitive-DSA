



object SolutionMLE {
    def dijkstra(dest: Int, distances: Map[Int, Double], t: Set[(Double, Int)], g: Map[Int, List[(Double, Int)]]): Double = {
        if (t.nonEmpty) {
            val (currWeight, currNode) = t.max
            if (g.contains(currNode)) {
                val (updatedQueue, updatedDistances) =
                    g(currNode).foldLeft((t.filter(_ != (currWeight, currNode)), distances)) { case ((newQueue, newDistances), (childWeight, childNode)) =>
                        if (childWeight * currWeight > newDistances.getOrElse(childNode, 0.0)) {
                            (newQueue + ((childWeight * currWeight, childNode)), newDistances.updated(childNode, childWeight * currWeight))
                        } else { (newQueue, newDistances) }
                    }
                dijkstra(dest, updatedDistances, updatedQueue, g)
            } else { distances.getOrElse(dest, 0.0) }
        } else { distances.getOrElse(dest, 0.0) }
    }

    def maxProbability(n: Int, edges: Array[Array[Int]], weights: Array[Double], start_node: Int, end_node: Int): Double = {
        val g = edges.foldLeft((0, Map[Int, List[(Double, Int)]]())) { case ((index, g), Array(source, dest)) =>
            val t = g.updated(source, g.getOrElse(source, List[(Double, Int)]()) :+ (weights(index), dest))
            (index + 1, t.updated(dest, t.getOrElse(dest, List[(Double, Int)]()) :+ (weights(index), source)))
        }.last
        dijkstra(end_node, Map[Int, Double](start_node -> 1.0), Set[(Double, Int)]((1.0, start_node)), g)
    }
}
