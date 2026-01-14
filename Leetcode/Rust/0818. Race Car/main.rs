



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;
/*
several very intereting ways to solve this problem; and in what follows, is
perhaps the most unintutive way. bfs/dfs are natural and way less taxing
choices; nevertheless, move novel approaches like CPS (continuation-passing style)
or trampolining with binary lifting could be used.
*/
impl Solution {
    #[allow(unused)]
    pub fn racecar(target: i32) -> i32 {
        let target = target as usize;
        let mut dp = vec![0i32; target + 1];

        for sub_target in 1..=target {
            dp[sub_target] = (1 << 30);
            let k = 32 - (sub_target as i32).leading_zeros();
            let reached = (1 << k) - 1;
            dp[sub_target] = match (reached, sub_target) {
                (r, s) if r == s => k as i32, // exact
                (r, s)           => { // overshot/undershot
                    // notwithstanding `reached` explore both cases[!]
                    dp[sub_target] = (k as i32) + 1i32 + dp[r - s]; // overshot
                    let f = ((1 << (k - 1)) - 1) as i32; // undershot
                    let mut res = dp[sub_target];
                    for m in 0..k {
                        let b = ((1 << m) - 1) as i32;
                        let r = sub_target as i32 - (f - b);
                        if r >= 0 {
                            res = std::cmp::min(res, (k + m + 1) as i32 + dp[r as usize]);
                        }
                    }; res
                }
            }
        }
        return dp[target];
    }
}

fn main() {}
