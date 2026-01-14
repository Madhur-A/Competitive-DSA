



// use itertools::Itertools;

#[allow(unused)]
struct Solution;

#[allow(unused)]
impl Solution {
    pub const INF: i32 = i32::MAX >> 1;
    // a very sub-optimal solution
    pub fn rx(
        nums: &Vec<i32>,
        base: &Vec<i32>,
        prev: i32,
        i: usize,
        seen: &mut std::collections::HashMap<(usize, i32), i32>,
    ) -> i32 {
        let n = nums.len();
        if i == n {
            return 0;
        }
        if seen.contains_key(&(i, prev)) {
            return *seen.get(&(i, prev)).unwrap();
        }

        let (mut pick, mut skip) = (Self::INF, Self::INF);

        let f = base.partition_point(|&e| e <= prev).min(base.len() - 1);
        if nums[i] > prev {
            skip = Self::rx(nums, base, nums[i], i + 1, seen);
        }
        if base[f] > prev {
            pick = 1 + Self::rx(nums, base, base[f], i + 1, seen);
        }

        let res = std::cmp::min(pick, skip);
        seen.insert((i, prev), res);

        return res;
    }

    pub fn make_array_increasing(arr1: Vec<i32>, arr2: Vec<i32>) -> i32 {
        let mut arr2 = arr2;
        arr2.sort_unstable();
        arr2.dedup();
        let mut seen = std::collections::HashMap::<(usize, i32), i32>::new();

        let res = Self::rx(&arr1, &arr2, -1, 0, &mut seen);
        return
            match res {
                Self::INF => -1,
                _         => res
        };
    }
}

fn main() {}
