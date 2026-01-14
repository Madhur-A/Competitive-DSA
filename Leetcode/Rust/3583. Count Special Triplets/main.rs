



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

const MAX: usize = 100_001;
const MOD: i64 = 1_000_000_007;

impl Solution {
    pub fn special_triplets(nums: Vec<i32>) -> i64 {
        let (mut suffix, mut prefix) = ([0i64; MAX + 1], [0i64; MAX]);
        let mut res = 0i64;
        for &num in nums.iter() {
            let (num, twice) = (num as usize, (num << 1) as usize);
            // the kye is to use `twice` instead of `half`; however it
            // is sheer coincidence that this maps well for this
            // methodology.
            res = (res + suffix[num]) % MOD;
            if twice < MAX {
                suffix[twice] = (suffix[twice] + prefix[twice]) % MOD;
            }
            prefix[num] += 1;
        }

        return res;
    }
}

fn main() {}
