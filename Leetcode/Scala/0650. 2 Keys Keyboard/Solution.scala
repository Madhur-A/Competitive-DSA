



object Solution {
    def memoize[I, O](f: I => O): I => O = collection.mutable.Map.empty[I, O].withDefault(key => f(key)).apply
    
    def minSteps(n: Int): Int = {
        def rx(n: Int): Int = n match {
            case 0 => 0
            case 1 => 0
            case 2 => 2
            case n => {
                val f = (2 until n).filter(n % _ == 0).collect { i => rx(i) + n / i } 
                if (f.isEmpty) n else f.min
            }
        }
        memoize(rx)(n)
    }
}

// more succinct version

object Solution {
    def memoize[I, O](f: I => O): I => O = collection.mutable.Map.empty[I, O].withDefault(key => f(key)).apply
    
    def minSteps(n: Int): Int = {
        def rx(n: Int): Int = {
            (2 until n).filter(n % _ == 0).map(i => rx(i) + n / i).minOption.getOrElse(if (n > 1) n else 0)
        }
        memoize(rx)(n)
    }
}

// even more succinct


object Solution {
    def memoize[I, O](f: I => O): I => O = collection.mutable.Map.empty[I, O].withDefault(key => f(key)).apply
    
    def minSteps(n: Int): Int = {
        memoize((n: Int) => (2 until n).filter(n % _ == 0).map(i => minSteps(i) + n / i).minOption.getOrElse(if (n > 1) n else 0))(n)
    }
}



