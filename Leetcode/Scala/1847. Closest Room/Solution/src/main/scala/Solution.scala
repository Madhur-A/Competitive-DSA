



object Solution {
    def closestRoom(rooms: Array[Array[Int]], queries: Array[Array[Int]]): Array[Int] = {
    }

    def main(args: Array[String]) = {
        val   rooms = Array(Array(2,2),Array(1,2),Array(3,2))
        val queries = Array(Array(3,1),Array(3,3),Array(5,2))
        println(closestRoom(rooms, queries).mkString("[", ",", "]"))
    }
}
