



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn max_absolute_sum(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut curr = (nums[0], nums[0]);
        let mut maxx = (nums[0], nums[0]);

        for i in 1..n {
            curr.0 = std::cmp::max(curr.0 + nums[i],  nums[i]);
            curr.1 = std::cmp::min(curr.1 + nums[i],  nums[i]);
            maxx.0 = std::cmp::max(maxx.0, curr.0);
            maxx.1 = std::cmp::min(maxx.1, curr.1);
        }

        return std::cmp::max(maxx.0.abs(), maxx.1.abs());
    }
}

fn main() {}
