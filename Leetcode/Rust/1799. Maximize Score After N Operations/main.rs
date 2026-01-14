



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn gcd(a: i32, b: i32) -> i32 {
        if b == 0 {
            a as i32
        } else {
            Self::gcd(b, a % b)
        }
    }

    pub fn dfs(
        nums: &Vec<i32>,
        dp: &mut Vec<Vec<i32>>,
        n: usize,
        prev: usize,
        count: usize,
    ) -> i32 {
        if count > (n >> 1) {
            return 0i32;
        }
        if dp[count][prev] != 0 {
            return dp[count][prev];
        }

        for i in 0..n {
            for j in (i + 1)..n {
                let curr = (1 << i) | (1 << j);
                if (curr & prev) == 0 {
                    dp[count][prev] = std::cmp::max(
                        dp[count][prev],
                        (count as i32) * Self::gcd(nums[i], nums[j])
                            + Self::dfs(nums, dp, n, curr | prev, count + 1),
                    );
                }
            }
        }

        return dp[count][prev];
    }

    pub fn max_score(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut dp = vec![vec![0i32; 1 << n]; (n >> 1) + 1];
        return Self::dfs(&nums, &mut dp, n, 0, 1);
    }
}

fn main() {}
