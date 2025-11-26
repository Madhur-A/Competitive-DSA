



#[allow(unused_imports)]
use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn find_left(nums: &Vec<i32>, target: i32) -> usize {
        pub fn rx(nums: &Vec<i32>, target: i32, left: usize, right: usize) -> usize {
            match left < right {
                false => left,
                true  => {
                    let mid = left + ((right - left) >> 1);
                    match nums[mid] < target {
                        false => rx(nums, target, left, mid),
                        true  => rx(nums, target, mid + 1, right),
                    }
                },
            }
        }
        rx(nums, target, 0, nums.len())
    }

    pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
        let nums_sorted = nums.iter().copied().sorted().collect::<Vec<i32>>();

        nums.iter().enumerate().fold(vec![0; nums.len()], |mut res, (index, &num)| {
            // res[index as usize] = Self::find_left(&nums_sorted, num) as i32; res
            // or using `partition_point`
            res[index] = nums_sorted.partition_point(|&e| e < num) as i32; res
        })
    }
}


fn main() {}
