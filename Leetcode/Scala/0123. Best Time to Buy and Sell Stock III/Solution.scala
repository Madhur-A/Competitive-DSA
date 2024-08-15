



object Solution {
    def maxProfit(prices: Array[Int]): Int = {
        prices.foldLeft((0, 0, Int.MinValue, Int.MinValue)) { case((s2, s1, b2, b1), price) =>
            (Math.max(s2, b2 + price), Math.max(s1, b1 + price), Math.max(b2, s1 - price), Math.max(b1, -price))
        }.head
    }
}

