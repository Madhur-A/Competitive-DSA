



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

// a bounded variation of [https://cses.fi/problemset/task/1140]

impl Solution {
    pub fn max_value(events: Vec<Vec<i32>>, k: i32) -> i32 {
        let (n, k) = (events.len(), k as usize);
        let mut events = events;
        events.sort_by_key(|event| event[1]);
        let mut dp = vec![vec![0i32; n + 1]; k + 1];

        for j in 1..=k {
            for i in 1..=n {
                let (mut left, mut right) = (0i32, i as i32 - 1);
                while left <= right {
                    let mid = left + ((right - left) >> 1);
                    if events[mid as usize][1] < events[i - 1][0] {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                let previous = if right >= 0 {
                    dp[j - 1][(right as usize) + 1]
                } else {
                    0i32
                };
                dp[j][i] = std::cmp::max(dp[j][i - 1], previous + events[i - 1][2]);
            }
        }

        return dp[k][n];
    }
}

fn main() {
    println!(
        "res: {}",
        Solution::max_value(vec![vec![1, 2, 4], vec![3, 4, 3], vec![2, 3, 1]], 2)
    );
}
