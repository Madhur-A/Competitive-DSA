



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn min_operations(n: i32) -> i32 {
        let mut num = n;
        let mut res = 0i32;

        while num > 0 {
            let expo  = (num as f64).log2() as i32;
            let left  = ((1 << expo) - num).abs(); // 2^(floor of the exponent)
            let right = ((1 << (expo + 1)) - num).abs(); // 2^(ceil of the exponent)
            num = std::cmp::min(left, right);
            res += 1i32;
        }

        return res;
    }

    // dp variant
    pub fn min_operations_dp(n: i32) -> i32 {
        if n == 1 { return 1; }
        if n <= 0 { return 0; }

        let offset = 1 << n.trailing_zeros();

        match n == offset {
            true  => return 1i32,
            false => {
                return 1 + std::cmp::min(
                    // turning off the first bit (from right [LSBs]) which is set
                    Self::min_operations_dp(n + offset), // by addition (recall 1 + 1 = 0 with 1 carry)
                    Self::min_operations_dp(n - offset), // or simply by removing its contribution from the constituent number
                )
            }
        }
    }
}

fn main() {}
