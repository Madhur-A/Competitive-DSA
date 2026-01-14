



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn maximum_profit(prices: Vec<i32>, txn: i32) -> i64 {
        let (n, txn) = (prices.len(), txn as usize);

        let mut dp = vec![vec![vec![0i64; txn + 1]; 3]; n];

        for k in 1..=txn {
            dp[0][1][k] = -prices[0] as i64;
            dp[0][2][k] =  prices[0] as i64;
        }

        for i in 1..n {
            let curr_price = prices[i] as i64;
            for k in 1..=txn {
                dp[i][0][k] = std::cmp::max(dp[i - 1][0][k], std::cmp::max(dp[i - 1][1][k] + curr_price, dp[i - 1][2][k] - curr_price));
                dp[i][1][k] = std::cmp::max(dp[i - 1][1][k], dp[i - 1][0][k - 1] - curr_price);
                dp[i][2][k] = std::cmp::max(dp[i - 1][2][k], dp[i - 1][0][k - 1] + curr_price);
            }
        }

        return dp[n - 1][0][txn];
    }
}

fn main() {}
