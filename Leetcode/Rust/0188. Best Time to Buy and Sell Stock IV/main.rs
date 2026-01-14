



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn max_profit(k_txn: i32, prices: Vec<i32>) -> i32 {
        let (n, txn) = (prices.len(), (k_txn + 1) as usize);

        let mut dp = vec![vec![vec![0i32; txn]; 2]; n];

        for k in 1..txn {
            dp[0][1][k] = -prices[0];
        }

        for i in 1..n {
            for k in 1..txn {
                dp[i][0][k] = std::cmp::max(dp[i - 1][0][k], dp[i - 1][1][k - 0] + prices[i]);
                dp[i][1][k] = std::cmp::max(dp[i - 1][1][k], dp[i - 1][0][k - 1] - prices[i]);
            }
        }

        return dp[n - 1][0][txn - 1];
    }
}

fn main() {}
