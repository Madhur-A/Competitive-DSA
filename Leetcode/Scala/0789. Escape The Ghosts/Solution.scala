



object Solution {
    def escapeGhosts(ghosts: Array[Array[Int]], target: Array[Int]): Boolean = {
        val t = math.abs(target(0)) + math.abs(target(1))
        ghosts.foldLeft(true) { case(res, ghost) => 
            res && (math.abs(ghost(0) - target(0)) + math.abs(ghost(1) - target(1)) > t)
        }
    }
}
