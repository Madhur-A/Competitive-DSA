



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn max_equal_rows_after_flips(matrix: Vec<Vec<i32>>) -> i32 {
        let mut res = 0i32;
        let mut seen = std::collections::HashMap::<[u64; 5], i32>::new();
        for row in matrix.iter() {
            let mut key = [0u64; 5]; // since 5 ~ (300 / 64)
            let first = row[0];
            for (i, &value) in row.iter().enumerate() {
                if value == first {
                    let (j, k) = (i.div_euclid(64), i.rem_euclid(64));
                    key[j] |= (1u64 << k);
                }
            }
            res = std::cmp::max(res, *seen.entry(key).and_modify(|v| *v += 1).or_insert(1));
        }

        return res;
    }

    pub fn max_equal_functional(matrix: Vec<Vec<i32>>) -> i32 { // one-liner (lol!)
        matrix.iter().fold((0i32, std::collections::HashMap::<[u64; 5], i32>::new()), |(res, mut seen), row| {
            (std::cmp::max(*seen.entry(row.iter().enumerate().fold(([0u64; 5], row[0]), |(mut key, first), (i, &value)| {
                let (j, k) = (i.div_euclid(64), i.rem_euclid(64));
                match value == first {
                    true  => key[j] |= (1u64 << k),
                    false => ()
                }
                (key, first)
            }).0).and_modify(|v| *v += 1).or_insert(1), res), seen)
        }).0
    }
}

fn main() {}
