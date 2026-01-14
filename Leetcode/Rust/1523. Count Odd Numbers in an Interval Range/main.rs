



#[allow(unused_imports)]
// use itertools::Itertools;
#[allow(unused)]
struct Solution;

impl Solution {
    pub fn count_odds(low: i32, high: i32) -> i32 {
        let count = high - low + 1;
        match count & 1 {
            0 => count >> 1,
            _ => match (low & 1, high & 1) {
                (0, 0) => count >> 1,
                (1, 1) => ((count - 2) >> 1) + 2,
                _      => i32::MAX, // unreachable
            },
        }
    }
}

fn main() {}
