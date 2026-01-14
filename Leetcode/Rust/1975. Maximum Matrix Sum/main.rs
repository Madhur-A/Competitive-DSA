



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn max_matrix_sum(grid: Vec<Vec<i32>>) -> i64 {
        let (negs, min_num, total) = grid.iter().fold((0i32, i32::MAX, 0i64), |(negs, min_num, total), row| {
            row.iter().fold((negs, min_num, total), |(negs, min_num, total), &num| {
                let new_total = total + num.abs() as i64;
                let new_min = std::cmp::min(min_num, num.abs());
                match num < 0 {
                    true  => (negs + 1, new_min, new_total),
                    false => (negs,     new_min, new_total)
                }
            })
        });

        match negs.rem_euclid(2) == 0 {
            true  => total,
            false => total - ((min_num as i64) << 1)
        }
    }
}

fn main() {}
