



object Solution {
    def retrieveInput(): Array[Array[Int]] = {
        val text = scala.io.Source.fromFile("input").mkString
        text.split('\n').map(e => e.split(',').map(_.toInt))
    }

    def diagonal(a: Array[Int], b: Array[Int]): Long = {
        val x = (a(0) - b(0)).toLong
        val y = (a(1) - b(1)).toLong
        val z = (a(2) - b(2)).toLong
        x*x + y*y + z*z
    }

    def one(): Unit = {
        val grid = retrieveInput(); // Array[Array[Int]]
        val distances =
            grid.indices.foldLeft(List[(Long, Int, Int)]()) { case (acc, i) =>
                (i + 1 until grid.length).foldLeft(acc) { case (acc, j) =>
                    (diagonal(grid(i), grid(j)), i, j) :: acc
                }
            }.sortBy(_._1)

        val r = grid.length
        val (roots, sizes) = ((0 to r).toArray, Array.fill(r + 1)(1))

        def find(i: Int): Int = (i == roots(i)) match { // DSU `find`
            case  true => roots(i)
            case false => roots(i) = find(roots(i)); roots(i)
        }

        def merge(i: Int, j: Int): Unit = { // DSU `merge`
            val (u, v) = (find(i), find(j))
            if (u != v) {
                val (h, k) = (sizes(u), sizes(v))
                if (h <= k) {
                    roots(u) = v
                    sizes(v) = sizes(v) + sizes(u)
                } else {
                    roots(v) = u
                    sizes(u) = sizes(u) + sizes(v)
                }
            }
        }

        val limit = 1000 // change this according to the problem constraint
        distances.take(limit).foldLeft(()) { case (_, (distance, i, j)) =>
            find(i) != find(j) match {
                case  true => merge(i, j)
                case false => ()
            }
        }

        val groupSizes = sizes.indices.map(i => find(i)).distinct.map(i => sizes(i)).sorted.reverse
        val res = groupSizes.take(3).product

        println(s"res: $res, ${res == 135169 || res == 40}")
    }

    def two(): Unit = {
        val grid = retrieveInput(); // Array[Array[Int]]
        val distances =
            grid.indices.foldLeft(List[(Long, Int, Int)]()) { case (acc, i) =>
                (i + 1 until grid.length).foldLeft(acc) { case (acc, j) =>
                    (diagonal(grid(i), grid(j)), i, j) :: acc
                }
            }.sortBy(_._1)

        val r = grid.length
        val (roots, sizes) = ((0 to r).toArray, Array.fill(r + 1)(1))

        def find(i: Int): Int = {
            if (i != roots(i)) {
                roots(i) = find(roots(i));
            }
            roots(i)
        }

        def merge(i: Int, j: Int): Unit = {
            val (u, v) = (find(i), find(j))
            if (u != v) {
                val (h, k) = (sizes(u), sizes(v))
                if (h <= k) {
                    roots(u) = v
                    sizes(v) = sizes(v) + sizes(u)
                } else {
                    roots(v) = u
                    sizes(u) = sizes(u) + sizes(v)
                }
            }
        }

        val limit = r - 1
        val (first, second, _) =
            distances.foldLeft((-1L, -1L, 0)) { case ((first, second, count), (distance, i, j)) =>
                find(i) != find(j) match {
                    case false => (first, second, count)
                    case  true => {
                        merge(i, j)
                        count + 1 == limit match {
                            case false => (first, second, count + 1)
                            case  true => (grid(i)(0), grid(j)(0), count + 1)
                        }
                    }
                }
            }

        val res = first * second
        println(s"res: $res, ${res == 302133440 || res == 25272}")
    }


    def main(args: Array[String]): Unit = {
        one()
        two()
    }
}
