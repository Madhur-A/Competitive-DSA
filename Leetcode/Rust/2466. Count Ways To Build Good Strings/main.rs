



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    const MOD: i64 = 1_000_000_007;

    pub fn count_good_strings(low: i32, high: i32, zero: i32, one: i32) -> i32 {
        let (lows, high, zero, ones) = (low as usize, high as usize, zero as usize, one as usize);

        // a fun one-liner
        /*
        (1..=high).fold(std::iter::once(1i64).chain(std::iter::repeat(0i64).take(high)).collect::<Vec<i64>>(), |mut dp, i| {
            if i >= zero { dp[i] = (dp[i] + dp[i - zero]).rem_euclid(Self::MOD); }
            if i >= ones { dp[i] = (dp[i] + dp[i - ones]).rem_euclid(Self::MOD); }
            dp
        }).iter().skip(lows).fold(0i64, |mut res, &e| {
            res = (res + e).rem_euclid(Self::MOD); res
        }) as i32
         */

        let mut dp = vec![0i64; high + 1];
        let mut res = 0i64;
        dp[0] = 1;
        for i in 1..=high {
            if i >= zero {
                dp[i] += dp[i - zero];
            }
            if i >= ones {
                dp[i] += dp[i - ones];
            }
            dp[i] = dp[i].rem_euclid(Self::MOD);
            if i >= lows {
                res = (res + dp[i]).rem_euclid(Self::MOD);
            }
        }

        return res as i32;
    }
}

fn main() {
    println!("{}", Solution::count_good_strings(3, 3, 1, 1));
}
