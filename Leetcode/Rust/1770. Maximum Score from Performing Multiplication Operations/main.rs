



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn maximum_score(nums: Vec<i32>, muxx: Vec<i32>) -> i32 {
        let (r, c) = (nums.len(), muxx.len());
        let mut dp = vec![vec![0i32; c + 1]; c + 1];

        let c = c - 1;
        for i in (0..=c).rev() {
            for left in (0..=i).rev() {
                let right = r - 1 - (i - left);
                dp[left][i] = std::cmp::max(
                    muxx[i] * nums[left] + dp[left + 1][i + 1],
                    muxx[i] * nums[right] + dp[left][i + 1],
                );
            }
        }

        return dp[0][0];
    }
}

fn main() {}
