



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

const MOD: i64 = 1_000_000_007;

impl Solution {
    pub fn count_permutations(computers: Vec<i32>) -> i32 {
        let mut min_so_far = computers[0];
        let mut res = 1i64;

        for i in 1..n {
            if computers[i] <= min_so_far {
                return 0;
            }
            let i = i as i64;
            res = (res + res * (i - 1)) % MOD;
        }

        return res as i32;
    }
}

fn main() {}
