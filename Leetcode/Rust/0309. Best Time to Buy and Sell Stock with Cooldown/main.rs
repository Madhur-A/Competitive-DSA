



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let n = prices.len();
        let mut dp = vec![vec![0i32; 2]; n];

        dp[0][1] = -prices[0];

        for i in 1..n {
            dp[i][0] = std::cmp::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = std::cmp::max(dp[i - 1][1], if i > 1 { dp[i - 2][0] - prices[i] } else { -prices[i] });
        }

        return dp[n - 1][0];
    }
}

fn main() {}
