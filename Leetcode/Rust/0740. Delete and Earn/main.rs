



struct Solution;

impl Solution {
    pub fn delete_and_earn(nums: Vec<i32>) -> i32 {
        let mut n = 0;
        let mut f = [0; 10001];
        nums.iter().for_each(|&num| { f[num as usize] += num; n = n.max(num); });

        let highest = n as usize;

        (2..=highest).fold((f[0], std::cmp::max(f[0], f[1])), |(prev, curr), i| {
            (curr, std::cmp::max(curr, prev + f[i]))
        }).1
    }
}

fn main() {}
