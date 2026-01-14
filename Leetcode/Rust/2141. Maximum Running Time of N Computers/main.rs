



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn condition(n: i64, t: i64, batteries: Vec<i64>) -> bool {
        n * t
            <= batteries
                .iter()
                .fold(0i64, |res, &battery| res + std::cmp::min(t, battery))
    }

    pub fn max_run_time(n: i32, batteries: Vec<i32>) -> i64 {
        let n = n as i64;
        let batteries = batteries
            .iter()
            .map(|&battery| battery as i64)
            .collect::<Vec<i64>>();
        let (mut left, mut right, mut mid) = (0i64, batteries.iter().sum::<i64>() / n, 0i64);
        // let mut is_valid = false;
        while left < right {
            mid = left + ((right - left + 1) >> 1) + (mid - mid); // suppressing warning that `mid` is never used
            /* to avoid cloning -- */
            // is_valid = n*mid <= batteries.iter().fold(0i64, |res, &battery| { res + std::cmp::min(mid, battery) });
            match Self::condition(n, mid, batteries.clone()) {
                true  => left  = mid,
                false => right = mid - 1,
            }
        }

        return left;
    }
}

fn main() {
    println!("res: {}", Solution::max_run_time(2, vec![3, 3, 3]));
}
