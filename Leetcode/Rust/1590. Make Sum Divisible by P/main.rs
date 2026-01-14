



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn min_subarray(nums: Vec<i32>, p: i32) -> i32 {
        let n = nums.len() as i32;
        let p = p as i32;
        let mut g = vec![(0i32, 0usize)]
            .into_iter()
            .collect::<std::collections::HashMap<i32, usize>>();

        let prefix = nums.iter().scan(0i32, |res, &num| {
            *res = (*res + num as i32).rem_euclid(p);
            Some(*res) /* `g` could be filled here (with `.enumerate()`) but then the intermediate results, if any, would be lost */
        }).collect::<Vec<i32>>();

        let last_sum = *prefix.last().unwrap();

        if last_sum == 0 {
            return 0i32;
        }

        let res = prefix.iter().enumerate().fold(n, |mut res, (index, &num)| {
            let target = (p + num - last_sum).rem_euclid(p);
            if let Some(found) = g.get(&target) {
                res = std::cmp::min(res, (index + 1 - found) as i32);
            };
            g.insert(num, index + 1) /*overwriting previous*/;
            res
        });

        match res == n {
            true  => -1,
            false => res,
        }
    }
}

fn main() {
    println!("res: {}", Solution::min_subarray(vec![3, 4, 1, 2], 6));
}
