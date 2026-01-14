



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn falling_squares(pxn: Vec<Vec<i32>>) -> Vec<i32> {
        let n = pxn.len();
        let mut ranges = Vec::<Vec<i32>>::new();
        let mut res = vec![0i32; n];

        let mut global_max = 0i32;

        for i in 0..n {
            let (mut left, mut right, height) = (pxn[i][0], pxn[i][0] + pxn[i][1], pxn[i][1]);
            let mut max_height = height;
            for range in ranges.iter() {
                let (range_left, range_right, range_height) = (range[0], range[1], range[2]);
                if range_right > left && right > range_left {
                    max_height = std::cmp::max(max_height, range_height + height);
                }
            }
            let resultant_height = max_height;
            global_max = std::cmp::max(global_max, resultant_height);
            res[i] = global_max;
            ranges.push(vec![left, right, resultant_height]);
        }

        return res;
    }
}

fn main() {}
