



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn max_turbulence_size(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut dp = vec![(0i32, 0i32); n];
        dp[0] = (1i32, 1i32);
        let mut res = 1i32;

        for i in 1..n {
            if nums[i] > nums[i - 1] {
                dp[i].0 = dp[i - 1].0 + 1;
                dp[i].1 = 1i32; // localized reset
            }
            if nums[i] < nums[i - 1] {
                dp[i].1 = dp[i - 1].1 + 1;
                dp[i].0 = 1i32; // localized reset
            }

            let (a, b) = &mut dp[i];
            std::mem::swap(a, b); // [!]
            res = std::cmp::max(res, *a.max(b));

            if nums[i] == nums[i - 1] {
                dp[i] = (1i32, 1i32); // global reset
            }
        }

        return res;
    }
}

fn main() {}
