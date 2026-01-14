



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn subset_sums(nums: &[i32]) -> Vec<i64> {
        let h = nums.len();
        let mut sums = vec![0i64; 1 << h];
        for i in (0..(1 << h)) {
            let mut total = 0i64;
            for j in 0..h {
                if (i & (1 << j)) != 0 {
                    total += nums[j] as i64;
                }
            }
            sums[i] = total;
        }
        return sums;
    }

    pub fn min_abs_difference(nums: Vec<i32>, goal: i32) -> i32 {
        let n = nums.len();

        let (first, second) = nums.split_at(n >> 1);

        let mut left = Self::subset_sums(first);
        let right = Self::subset_sums(second);

        left.sort();
        let goal = goal as i64;
        let mut res = i64::MAX as i64;

        for total in right.iter() {
            let target = goal - total;

            match left.binary_search(&target) {
                Ok(_) => return 0i32,
                Err(j) => {
                    let f = std::cmp::min(left.len() - 1, j); // found index
                    let p = f.saturating_sub(1); // previous index
                    res = std::cmp::min(res, (left[f] + total - goal).abs());
                    res = std::cmp::min(res, (left[p] + total - goal).abs());
                }
            }
        }

        return res as i32;
    }
}

fn main() {}
