



object Solution {
    def canConstruct(s: String, k: Int): Boolean = (k <= s.length) match {
        case true  => s.groupBy(identity).view.mapValues(_.length).map(_.last).count(e => (e & 1) == 1) <= k
        case false => false
    }
}
