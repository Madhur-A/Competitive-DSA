



// certainly NOT functional

import scala.collection.mutable.{Set, ArrayBuffer}

object Solution {
    def smallestSubsequence(s: String): String = {
        val indices = s.zipWithIndex.groupBy(_._1).view.mapValues(_.last.last + 1)

        s.foldLeft((ArrayBuffer[Char](), Set[Char](), 0)) { case ((res, seen, index), element) =>
            if (!seen.contains(element)) {
                while (!res.isEmpty && res.last > element && index < indices(res.last)) {
                    seen.remove(res.last)
                    res.remove(res.indices.last)
                }
                seen.add(element)
                res.addOne(element)
            }
            (res, seen, index + 1)
        }.head.mkString
    }
}
