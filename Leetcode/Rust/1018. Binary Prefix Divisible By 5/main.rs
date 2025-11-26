



#[allow(unused_imports)]
use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn prefixes_div_by5(nums: Vec<i32>) -> Vec<bool> {
        // nums.iter().fold((vec![false; nums.len()], 0i32, 0usize), |(mut res, mut rem, i), &num| {
        //     rem = ((rem << 1) | num).rem_euclid(5);
        //     if rem == 0 { res[i] = true; }
        //     (res, rem, i + 1)
        // }).0

        let mut curr = 0;
        nums.iter().map(|num| { curr = ((curr << 1) | num).rem_euclid(5); curr == 0 }).collect::<Vec<bool>>()
    }
}


fn main() {}
