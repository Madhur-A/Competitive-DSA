



object Solution {
    def parse(timeString: String): Int = {
        val Array(hours, minutes) = timeString.split(":").map(_.toInt)
        hours * 60 + minutes
    }
    
    def getRes(times: List[Int], res: Int = Int.MaxValue): Int = {
        if (times.length == 2) { math.min(res, times.last - times.head) } else {
            val newRes = times.tail.head - times.head
            getRes(times.tail, math.min(res, newRes))
        }
    }
    
    def findMinDifference(timePoints: List[String]): Int = {
        if (timePoints.length <= 1440) {
            val listOfTimes = timePoints.map(parse).toList.sorted
            getRes(listOfTimes.appended(listOfTimes.head + 1440))
        } else { 0 }
    }
}
