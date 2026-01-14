



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn job_scheduling(start_time: Vec<i32>, end_time: Vec<i32>, profit: Vec<i32>) -> i32 {
        let n = start_time.len();
        let mut elems = (0..n)
            .map(|i| (start_time[i], end_time[i], profit[i]))
            .collect::<Vec<(i32, i32, i32)>>();

        elems.sort();

        let mut nexts = (0..n)
            .map(|i| i + 1 + elems[i + 1..].partition_point(|e| e.0 < elems[i].1))
            .collect::<Vec<usize>>();

        let mut dp = vec![0i32; n + 1];

        for i in (0..n).rev() {
            dp[i] += std::cmp::max(dp[i + 1], dp[nexts[i]] + elems[i].2);
        }

        return dp[0];
    }
}

fn main() {}
