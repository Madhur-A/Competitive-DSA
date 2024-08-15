



object Solution {
    def maxProfit(prices: Array[Int]): Int = {
        prices.foldLeft((0, -prices.head)) { case ((sell, buy), price) =>
            (Math.max(sell, buy + price), Math.max(buy, sell - price))
        }.head
    }
}
