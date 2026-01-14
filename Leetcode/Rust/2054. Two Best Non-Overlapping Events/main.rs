



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    fn max_k_events(mut events: Vec<Vec<i32>>, k: usize) -> i32 {
        let n = events.len();
        events.sort();

        let mut nexts = (0..n)
            .map(|i| i + 1 + events[i + 1..].partition_point(|e| e[0] <= events[i][1]))
            .collect::<Vec<usize>>();

        let mut dp = vec![vec![0i32; k + 1]; n + 1];
        for i in (0..n).rev() {
            for j in 1..=k {
                dp[i][j] = std::cmp::max(dp[i + 1][j], events[i][2] + dp[nexts[i]][j - 1]);
            }
        }

        return dp[0][k];
    }

    pub fn max_two_events(events: Vec<Vec<i32>>) -> i32 {
        return Self::max_k_events(events, 2);
    }
}

fn main() {}
