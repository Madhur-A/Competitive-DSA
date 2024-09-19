



object Solution {
    def maxProfit(prices: Array[Int]): Int = {
        prices.foldLeft((0, prices(0))) { case ((res, minSoFar), price) =>
            (Math.max(res, price - minSoFar), Math.min(price, minSoFar))
        }.head
    }
}
