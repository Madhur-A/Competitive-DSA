



object Solution {
    def winnerOfGame(colors: String): Boolean = {
        val n = colors.length
        var a, b = 0
        var left = 0
        while(left < n) {
            var right = left
            while(right < n && colors(right) == colors(left)) { right += 1; }
            val count = if (right - left - 2 > 0) right - left - 2 else 0
            if(colors(left) == 'A') then a += count else b += count
            left = right
        }
        a > b
    }
}
