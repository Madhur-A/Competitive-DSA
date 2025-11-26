



#[allow(unused_imports)]
use std::collections::HashSet;
use itertools::{FoldWhile, Itertools};

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn find_final_value(nums: Vec<i32>, original: i32) -> i32 {
        let seen = nums.into_iter().collect::<HashSet<i32>>();

        (0..).fold_while(original, |target, _| {
            match seen.contains(&target) {
                true  => FoldWhile::Continue(target << 1),
                false => FoldWhile::Done(target),
            }
        }).into_inner()
    }
}

fn main() {}
