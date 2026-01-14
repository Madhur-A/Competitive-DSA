



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let (mut cmin, mut cmax, mut gmax) = (nums[0], nums[0], nums[0]);
        let mut temp = 0i32;

        for i in 1..n {
            if nums[i] < 0 {
                std::mem::swap(&mut cmin, &mut cmax);
            }

            cmax = std::cmp::max(nums[i], cmax * nums[i]);
            cmin = std::cmp::min(nums[i], cmin * nums[i]);
            gmax = std::cmp::max(gmax, cmax);
        }

        return gmax;
    }
}

fn main() {}
