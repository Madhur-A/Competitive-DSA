



import scala.collection.mutable.LinkedHashMap

object Solution {
    def kthDistinct(words: Array[String], k: Int): String = {
        words.foldLeft(LinkedHashMap.empty[String, Int]) { (map, word) => map.clone().addOne(word, map.getOrElse(word, 0) + 1) }.filter(_._2 == 1).keys.toList.lift(k-1).getOrElse("")
    }
}
