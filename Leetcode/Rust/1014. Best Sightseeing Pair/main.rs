



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn max_score_sightseeing_pair(nums: Vec<i32>) -> i32 {
        nums.iter().enumerate().skip(1).fold((0i32, nums[0]), |(res, max_left), (i, &num)| {
            (res.max(num + max_left - i as i32), max_left.max(num + i as i32))
        }).0
    }
}

fn main() {
    println!("res: {}", Solution::max_score_sightseeing_pair(vec![8,1,5,2,6]));
    println!(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!");
}
