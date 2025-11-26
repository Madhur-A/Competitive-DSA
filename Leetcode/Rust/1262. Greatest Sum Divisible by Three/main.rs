



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn max_sum_div_three(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut dp = vec![vec![i32::MIN >> 1; 3]; n + 1];
        dp[0][0] = 0;

        for i in 1..=n {
            for j in 0..=2 {
                let k = (j + nums[i - 1]).rem_euclid(3) as usize;
                let j = j as usize;
                dp[i][j] = std::cmp::max(dp[i][j], dp[i - 1][j]);
                dp[i][k] = std::cmp::max(dp[i][k], dp[i - 1][j] + nums[i - 1]);
            }
        }

        dp[n][0]
    }
}


fn main() {
    let nums = vec![3,6,5,1,8];
    println!("res = {}", Solution::max_sum_div_three(nums));
}
