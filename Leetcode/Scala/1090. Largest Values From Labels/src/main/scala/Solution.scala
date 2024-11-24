



object Solution {
    def largestValsFromLabels(values: Array[Int], labels: Array[Int], numWanted: Int, useLimit: Int): Int = {
        def rx(items: Array[(Int, Int)], have: Map[Int, Int], count: Int): Int = (items.isEmpty || (count == numWanted)) match {
            case  true => 0
            case false => {
                val (value, label) = items.head
                val currFreq = have.getOrElse(label, 0)
                (currFreq < useLimit) match {
                    case  true => value + rx(items.tail, have.updated(label, currFreq + 1), count + 1)
                    case false =>         rx(items.tail, have.updated(label, currFreq + 1), count)
                }
            }
        }

        rx(values.zip(labels).sorted.reverse, Map[Int, Int](), 0)
    }
}
