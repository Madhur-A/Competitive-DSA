



// certainly NOT functional

object Solution {
    def processQueries(queries: Array[Int], m: Int): Array[Int] = {
        var nums = scala.collection.mutable.ArrayBuffer() ++ (1 to m)
        queries.zipWithIndex.foldLeft(Array.fill(queries.length)(0)) { case (res, (query, index)) =>
            res(index) = nums.indexOf(query)
            nums.remove(res(index))
            nums.prepend(query); res
        }
    }
}
