// caution: this is NOT functional, for a pure functional version refer to
// SolutionMLE. 


import scala.collection.mutable.PriorityQueue

object Solution {
    def dijkstra(n: Int, source: Int, dest: Int, g: Map[Int, List[(Double, Int)]]): Double = {
        val distances = Array.fill(n)(0.0)
        distances.update(source, 1.0)
        val t = PriorityQueue[(Double, Int)]((1.0, source))
        while (t.nonEmpty) {
            val (currWeight, currNode) = t.dequeue()
            if (g.contains(currNode)) {
                g(currNode).foreach { edge =>
                    val (childWeight, childNode) = (edge.head, edge.last)
                    if (childWeight * currWeight > distances(childNode)) {
                        distances.update(childNode, childWeight * currWeight)
                        t.enqueue((childWeight * currWeight, childNode))
                    }
                }
            } else { return 0.0 }
        }
        return distances(dest)
    }

    def maxProbability(n: Int, edges: Array[Array[Int]], weights: Array[Double], start_node: Int, end_node: Int): Double = {
        dijkstra(
            n,
            start_node,
            end_node,
            edges.foldLeft((0, Map[Int, List[(Double, Int)]]())) { case ((index, g), edge) =>
                val Array(source, dest) = edge
                val temp = g.updated(source, (weights(index), dest) :: g.getOrElse(source, List[(Double, Int)]()))
                (index + 1, temp.updated(dest, (weights(index), source) :: g.getOrElse(dest, List[(Double, Int)]())))
            }.last
        )
    }
}
