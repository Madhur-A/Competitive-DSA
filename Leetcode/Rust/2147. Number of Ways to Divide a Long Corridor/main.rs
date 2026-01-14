



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

const MOD: i64 = 1_000_000_007;

impl Solution {
    #[allow(unused)]
    pub fn number_of_ways(corridor: String) -> i32 {
        let n = corridor.len();
        let mut dp = vec![vec![0i64; 3]; n];
        let corridor = corridor.as_bytes();

        if corridor[0] == b'S' { dp[0][1] = 1; } else { dp[0][0] = 1; }

        for i in 1..n {
            if corridor[i] == b'S' {
                dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]).rem_euclid(MOD);
                dp[i][2] =  dp[i - 1][1];
            } else {
                dp[i][0] = (dp[i - 1][0] + dp[i - 1][2]).rem_euclid(MOD);
                dp[i][1] =  dp[i - 1][1];
                dp[i][2] =  dp[i - 1][2];
            }
        }

        return dp[n - 1][2] as i32;
    }
}

fn main() { println!("res: {}", Solution::number_of_ways("SSPPSPS".into())); }
