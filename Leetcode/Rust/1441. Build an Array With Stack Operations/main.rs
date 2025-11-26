



#[allow(unused_imports)]
use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn build_array(target: Vec<i32>, _n: i32) -> Vec<String> {
        target.iter().fold((Vec::new(), 1), |(mut res, mut curr), &num| {
            while curr < num {
                res.push("Push".into());
                res.push("Pop".into());
                curr += 1;
            }
            res.push("Push".into());
            (res, curr + 1)
        }).0
    }
}

fn main() {}
