



object Solution {
    def numTeams(rating: Array[Int]): Int = {
       rating.indices.foldLeft(0) { case (res, i) =>
            val lower  = rating.take(i).count(_ < rating(i))
            val higher = rating.drop(i + 1).count(_ > rating(i))
            res + lower * higher + (i - lower) * (rating.length - i - 1 - higher)
        }
    }
}

