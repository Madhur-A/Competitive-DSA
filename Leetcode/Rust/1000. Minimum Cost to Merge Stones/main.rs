



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

// similar interval dp/palindrome problems:
// 0312. Burst Balloons
// 0546: Remove Boxes
// ...

impl Solution {
    #[allow(unused)]
    pub fn merge_stones(stones: Vec<i32>, k: i32) -> i32 {
        let (n, k) = (stones.len(), k as usize);

        if (n - 1).rem_euclid(k - 1) != 0 { return -1i32; }

        let prefix = std::iter::once(0i32).chain(stones).scan(0i64, |acc, num| {
            *acc += num as i64; Some(*acc)
        }).collect::<Vec<i64>>();

        let mut dp = vec![vec![(i32::MAX >> 1) as i64; n]; n];
        for i in 0..n { dp[i][i] = 0; }

        for ln in 2..=n {
            for left in 0..(n - ln + 1) {
                let right = left + ln - 1;
                for mid in (left..right).step_by(k - 1) {
                    dp[left][right] = std::cmp::min(dp[left][right], dp[left][mid] + dp[mid + 1][right]);
                }

                if (ln - 1).rem_euclid(k - 1) == 0 {
                    dp[left][right] += prefix[right + 1] - prefix[left];
                }

            }
        }


        return dp[0][n - 1] as i32;
    }
}

fn main() {
    println!("res: {}", Solution::merge_stones(vec![3,2,4,1], 2));
    println!("res: {}", Solution::merge_stones(vec![3,2,4,1], 3));
    println!("res: {}", Solution::merge_stones(vec![3,5,1,2,6], 3));

    println!(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!");
}
