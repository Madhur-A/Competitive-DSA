



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn maximize_win(prize_positions: Vec<i32>, k: i32) -> i32 {
        let n = prize_positions.len();
        let mut dp = vec![0i32; n + 1];
        let mut res = 0i32;

        for i in 1..=n {
            let curr = prize_positions[i - 1];
            let j = prize_positions.partition_point(|&e| e < curr - k);
            res = std::cmp::max(res, dp[j] + (i - j) as i32);
            dp[i] = std::cmp::max(dp[i - 1], (i - j) as i32);
        }

        return res;
    }
}

fn main() {}
