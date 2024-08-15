



object Solution {
    def maxProfit(prices: Array[Int]): Int = {
        prices.foldLeft((0, Int.MinValue, 0)) { case ((sell, buy, prev), price) =>
            (Math.max(sell, buy + price), Math.max(buy, prev - price), sell)
        }.head
    }
}

