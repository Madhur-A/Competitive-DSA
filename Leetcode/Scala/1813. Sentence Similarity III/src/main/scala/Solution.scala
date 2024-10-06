



// full-on pattern-matching

object Solution {
    def areSentencesSimilar(s: String, t: String): Boolean = (t.length <= s.length) match {
        case false  => areSentencesSimilar(t, s)
        case true   => {
            def gauge(sw: List[String], tw: List[String]): Boolean = tw.isEmpty match {
                case true  => true
                case false => sw.head == tw.head match {
                    case true  => gauge(sw.tail, tw.tail)
                    case false => sw.last == tw.last match {
                        case true  => gauge(sw.dropRight(1), tw.dropRight(1))
                        case false => false
                    }
                }
            }
            gauge(s.split(" ").toList, t.split(" ").toList) // "Ooarai Joshigakuin Shōri!"
        }
    }
}
