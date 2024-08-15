



object Solution {
    def maxProfit(prices: Array[Int], fee: Int): Int = {
        prices.foldLeft((0, -prices.head)) { case ((sell, buy), price) =>
            (Math.max(sell, buy + price - fee), Math.max(buy, sell - price))
        }.head
    }
}

