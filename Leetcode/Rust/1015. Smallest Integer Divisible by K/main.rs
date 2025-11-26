#[allow(unused_imports)]
// use itertools::Itertools;
// use std::env;
#[allow(unused)]
struct Solution;

impl Solution {
    pub fn smallest_repunit_div_by_k(k: i32) -> i32 {
        if k == 1 {
            return 1;
        }
        if k.rem_euclid(5) == 0 || k.rem_euclid(2) == 0 {
            return -1;
        }

        match (1..=k).try_fold((1 % k, 1), |(rem, res), _| match rem {
            0 => Err(res),
            _ => Ok(((rem * 10 + 1).rem_euclid(k), res + 1)),
        }) {
            Err(res) => res,
            Ok(_)    => -1,
        }
    }
}

fn main() {
    // let args = std::env::args().collect::<Vec<String>>();
    // let number = if args.len() == 1 { 4649 } else { args[1].parse::<i32>().unwrap_or(0) };
    // println!("{:?}", Solution::smallest_repunit_div_by_k(number));
}
