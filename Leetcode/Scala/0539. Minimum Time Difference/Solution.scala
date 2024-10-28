



object Solution {
    def parse(timeString: String): Int = {
        val Array(hours, minutes) = timeString.split(":").map(_.toInt)
        hours * 60 + minutes
    }

    def getRes(times: List[Int], res: Int = Int.MaxValue): Int = (times.length == 2) match {
        case  true => math.min(res, times.last - times.head)
        case false => getRes(times.tail, math.min(res, times.tail.head - times.head))
    }

    def findMinDifference(timePoints: List[String]): Int = (timePoints.length <= 1440) match {
        case  true => {
            val listOfTimes = timePoints.map(parse).sorted
            getRes(listOfTimes.appended(listOfTimes.head + 1440))
        }
        case false => 0
    }
}
