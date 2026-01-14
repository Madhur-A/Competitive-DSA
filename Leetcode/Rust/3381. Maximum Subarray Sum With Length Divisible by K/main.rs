



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn max_subarray_sum(nums: Vec<i32>, k: i32) -> i64 {
        // a simple two-liner ;)
        let gen_vector = |r: i32| {
            (0..r)
                .map(|i| if i == (r - 1) { 0i64 } else { 1E18 as i64 })
                .collect::<Vec<i64>>()
        };

        nums.iter()
            .enumerate()
            .fold(
                (-1E18 as i64, 0i64, gen_vector(k)),
                |(res, mut prefix, mut min_sums), (index, &num)| {
                    let rem_index = (index).rem_euclid(k as usize) as usize;
                    let prv_value = min_sums[rem_index];
                    prefix += (num as i64);
                    min_sums[rem_index] = min_sums[rem_index].min(prefix);
                    (std::cmp::max(res, prefix - prv_value), prefix, min_sums)
                },
            ).0
    }

    pub fn max_subarray_sum(nums: Vec<i32>, k: i32) -> i64 {
        // a simple one-liner ;)
        nums.iter()
            .scan(0i64, |total, &num| {
                *total += num as i64;
                Some(*total)
            })
            .collect::<Vec<i64>>()
            .iter()
            .enumerate()
            .fold(
                (
                    -1E18 as i64,
                    (0..k)
                        .map(|i| if i == (k - 1) { 0i64 } else { 1E18 as i64 })
                        .collect::<Vec<i64>>(),
                ),
                |(res, mut min_sums), (index, &total)| {
                    let rem_index = (index).rem_euclid(k as usize) as usize;
                    let prv_value = min_sums[rem_index];
                    min_sums[rem_index] = std::cmp::min(prv_value, total);
                    (std::cmp::max(res, total - prv_value), min_sums)
                },
            ).0
    }
}

fn main() {}
