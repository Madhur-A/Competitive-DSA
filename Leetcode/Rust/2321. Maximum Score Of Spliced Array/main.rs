



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn maximums_spliced_array(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let n = nums1.len();

        let diff = (0..n)
            .into_iter()
            .map(|i| (nums1[i] - nums2[i], nums2[i] - nums1[i]))
            .collect::<Vec<(i32, i32)>>();

        let (mut res, mut curr) = (diff[0], diff[0]);

        for i in 1..n {
            curr.0 = std::cmp::max(curr.0 + diff[i].0, diff[i].0);
            curr.1 = std::cmp::max(curr.1 + diff[i].1, diff[i].1);

            res.0 = std::cmp::max(curr.0, res.0);
            res.1 = std::cmp::max(curr.1, res.1);
        }

        return std::cmp::max(
            res.0 + nums2.iter().sum::<i32>(),
            res.1 + nums1.iter().sum::<i32>(),
        );
    }
}

fn main() {}
