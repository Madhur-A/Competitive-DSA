



object Solution {
    def minimumDeletions(s: String): Int = {
        s.foldLeft((0, 0)) { case((res, count), char) => 
            if(char == 'a') {
                (Math.min(res+1, count), count)
            } else {
                (res, count+1)
            }
        }._1
    }
}
