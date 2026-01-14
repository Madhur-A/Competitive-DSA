



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

/**
 * this is a traditional sliding window problem, with a misleading name.
 * however, in the spirit of other DP problems with stock-buy-sell;
 * dynamic-programming is attempted; which looks
 * absurd, to be honest; but at least it is succinct.
**/

impl Solution {
    #[allow(unused)]
    pub fn max_profit(prices: Vec<i32>, strategy: Vec<i32>, k: i32) -> i64 {
        let (n, k, m) = (prices.len(), k as usize, (k >> 1) as usize);
        let mut dp = vec![vec![0i64; 2]; n + 1];

        let prefix = std::iter::once(0i64)
            .chain(prices.iter().scan(0i64, |res, &price| {
                *res += price as i64;
                Some(*res)
            }))
            .collect::<Vec<i64>>();

        for i in 1..=n {
            for j in 0..=1 {
                let skip = dp[i - 1][j] + (strategy[i - 1] * prices[i - 1]) as i64;
                let pick = if k <= i && j == 0 {
                    dp[i - k][1] + prefix[i] - prefix[i - m]
                } else {
                    i64::MIN
                };
                dp[i][j] = std::cmp::max(pick, skip);
            }
        }

        return dp[n][0];
    }
}

fn main() {}
