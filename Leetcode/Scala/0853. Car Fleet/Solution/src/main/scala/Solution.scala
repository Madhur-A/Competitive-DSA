// "Ooarai Joshigakuin Shōri!"



object Solution {
    def carFleet(target: Int, position: Array[Int], speed: Array[Int]): Int = {
        position.zip(speed).sorted.reverse.foldLeft((0, 0.0)) { case ((numberOfFleets, prevTime), (distance, speed)) =>
            ((target - distance).toDouble / speed) match {
                case x if x <= prevTime => (numberOfFleets, prevTime)
                case x                  => (numberOfFleets + 1, x)
            }
        }.head
    }
}
