



#[allow(unused_imports)]
// use itertools::Itertools;
use std::collections::HashMap;

#[allow(unused)]
struct Solution;



impl Solution {
    #[allow(unused)]
    pub fn dfs(batch_size: usize, curr_state: i64, curr_rem: i32, dp: &mut HashMap) -> i32 {
        if dp.contains(curr_state) { return &dp[curr_state]; }
        let mut res = 0i32;

        for rem in 1..batch_size {
            let group_count = (curr_state >> (rem * 5)) & 31;
            if group_count > 0 {
                let next_state = curr_state - (1i64 << (rem * 5));
                let next_rem = (curr_rem + rem).rem_euclid(batch_size as i64);
                let next_count = dfs(batch_size, next_state, next_rem, dp);
                let curr_res = if curr_rem == 0 { 1 } else { 0 };
                res = std::cmp::max(res, curr_res + next_count);
            }
        }
        return res;
    }

    pub fn max_happy_groups(batch_size: i32, groups: Vec<i32>) -> i32 {
        let n = groups.len();
        let mut res = groups.iter().map(|e| e.rem_euclid(batch_size)).count(0);
        let mut dp = HashMap::<i64, i32>::new();
        let mut state = 0i32;

        return res + dfs(batch_size as usize, state, 0, &mut dp);
    }
}

fn main() {}
