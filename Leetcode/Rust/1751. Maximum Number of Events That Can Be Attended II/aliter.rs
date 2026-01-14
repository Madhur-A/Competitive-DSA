



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

// alternate construction based on 2054, 1235 and likewise

impl Solution {
    #[allow(unused)]
    pub fn max_value(events: Vec<Vec<i32>>, k: i32) -> i32 {
        let n = events.len();
        let mut events = events;
        events.sort();
        let nexts = (0..n)
            .map(|i| i + 1 + events[i + 1..].partition_point(|e| e[0] <= events[i][1]))
            .collect::<Vec<usize>>();
        let k = k as usize;
        let mut dp = vec![vec![0i32; k + 1]; n + 1];

        for i in (0..n).rev() {
            for j in 1..=k {
                dp[i][j] = std::cmp::max(dp[i + 1][j], dp[nexts[i]][j - 1] + events[i][2]);
            }
        }

        return dp[0][k];
    }
}

fn main() {}
