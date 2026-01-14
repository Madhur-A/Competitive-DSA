



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn count_subarrays(nums: Vec<i32>, k: i64) -> i64 {
        let n = nums.len();
        let (mut sum, mut res) = (0i64, 0i64);

        let mut left = 0usize;

        for right in 0..n {
            sum += nums[right] as i64;
            while k <= sum * (right - left + 1) as i64 {
                //  combining `left < right` would break the invariant
                // `sum * (right - left + 1)` would become negative eventually
                //  and loop would be exited.
                sum -= nums[left] as i64;
                left += 1;
            }

            res += (right - left + 1) as i64;
        }

        return res;
    }
}

fn main() {}
