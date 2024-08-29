



class MergeFind private (val roots: Array[Int], val ranks: Array[Int]) {
    def this(numberOfElements: Int) = {
        this(Array.tabulate(numberOfElements + 10)(identity), new Array[Int](numberOfElements + 10))
    }

    def find(index: Int): Int = {
        if (roots(index) == index) index else {
            roots.update(index, find(roots(index)))
            roots(index)
        }
    }

    def merge(u: Int, v: Int): Unit = {
        val (uRoot, vRoot) = (find(u), find(v))
        if (uRoot != vRoot) {
            val (uRank, vRank) = (ranks(uRoot), ranks(vRoot))
            if (uRank < vRank) {
                roots.update(uRoot, vRoot)
            } else {
                roots.update(vRoot, uRoot)
                ranks.update(uRoot, ranks(vRoot) + 1)
            }
        }
    }

    def uniqueRoots(edges: Array[Array[Int]]): Int = {
        edges.length - 
        edges.foldLeft(scala.collection.mutable.Set[Int]()) { case (seen, edge) =>
            seen.addOne(find(edge.head)); seen
        }.size
    }
}

object MergeFind {
    def apply(edges: Array[Array[Int]]): Int = {
        val maxVertex = edges.flatten.max
        val mergeFind = new MergeFind(maxVertex + maxVertex + 1)
        edges.foreach { edge => mergeFind.merge(edge.head, edge.last + maxVertex + 1) }
        mergeFind.uniqueRoots(edges)
    }
}

object Solution {
    def removeStones(stones: Array[Array[Int]]): Int = {
        MergeFind(stones)
    }    

    def response: String = removeStones(Array(Array(0,1),Array(1,0))).toString
}
