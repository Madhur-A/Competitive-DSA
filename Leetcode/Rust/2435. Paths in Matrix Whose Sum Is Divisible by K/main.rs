



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

const MOD: i32 = 1_000_000_007;

// somewhat similar to `https://codeforces.com/contest/2/problem/B`
// though this one is opitmized using modular arithmetic; thereby
// avoiding two-state/twice dp traversal.

impl Solution {
    pub fn number_of_paths(grid: Vec<Vec<i32>>, k: i32) -> i32 {
        let r = grid.len();
        let c = grid[0].len();
        let l = k as usize;

        let mut dp = vec![vec![vec![0i32; l]; c]; r];

        dp[0][0][(grid[0][0]).rem_euclid(k) as usize] = 1;

        for i in 0..r {
            for j in 0..c {
                for e in 0..l { // remainders
                    let s = (grid[i][j] + e as i32).rem_euclid(k) as usize;
                    if i > 0 {
                        dp[i][j][s] += dp[i - 1][j][e];
                        dp[i][j][s]  = dp[i][j][s].rem_euclid(MOD);
                    }
                    if j > 0 {
                        dp[i][j][s] += dp[i][j - 1][e];
                        dp[i][j][s]  = dp[i][j][s].rem_euclid(MOD);
                    }
                }
            }
        }

        return dp[r - 1][c - 1][0];
    }
}

fn main() {
    // println!("res: {}", Solution::number_of_paths(vec![vec![7,3,4,9],vec![2,3,6,2],vec![2,3,7,0]], 1));
}
