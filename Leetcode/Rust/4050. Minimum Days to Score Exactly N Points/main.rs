



#[allow(unused_imports)]
// use itertools::Itertools;
// use std::collections::HashMap;

#[allow(unused)]
struct Solution;

// basically a variant of coin-change; however here
// the methodology is more or less that of mathematical
// optimum finding since a quadratic (hence only two roots)
// is in play.

impl Solution {
    #[allow(unused)]
    pub fn min_days(n: i32) -> i32 {
        let   tri = |k: i32| { return (k * (k + 1)).div_euclid(2); }; // summation
        // roots of the quadratic
        let alpha = |k: i32| { return ((8*k + 1).isqrt() - 1).div_euclid(2); };
        let  beta = |k: i32| ((8*k - 7).isqrt() + 1).div_euclid(2);

        fn lower_bound(target: i32, costed: i32) -> i32 {
            if target <= 0 { return 0; }
            if costed <= 0 { return i32::MAX; }
            if costed == 1 { return target << 1; }

            let curr = (costed * (costed + 1)).div_euclid(2);
            let cost = costed + 1;

            let  quotient = target.div_euclid(curr);
            let remainder = target.rem_euclid(curr);

            if remainder == 0 { return quotient * cost; }

            return quotient * cost + ((8*remainder - 7).isqrt() + 1).div_euclid(2) + 1;
        }

        fn g_estimate(target: i32, mut costed: i32) -> i32 {
            let mut curr = target;
            let mut cost = 0;
            while curr > 0 {
                let upper_l = ((8*curr + 1).isqrt() - 1).div_euclid(2);
                costed = std::cmp::max(costed, upper_l);
                if costed <= 0 { return i32::MAX; }
                cost += costed + 1;
                curr -= (costed * (costed + 1)).div_euclid(2);
            }

            return cost;
        }

        // twin functions; common gimmick used in functional programming
        fn sling(target: i32, mut costed: i32) -> i32 {
            if target <= 0 { return 0; }
            if costed <= 0 { return i32::MAX; }

            let upper_l = ((8*target + 1).isqrt() - 1).div_euclid(2);
            let costed  = std::cmp::max(costed, upper_l);
            if costed <= 0 { return i32::MAX; }

            return fetch(target, costed);
        }
        fn fetch(target: i32, mut costed: i32) -> i32 {
            if costed == 1 { return target << 1; }
            let l_est = lower_bound(target, costed);
            let u_est = g_estimate(target, costed);

            let mut res = u_est;

            if u_est <= l_est { return u_est; }

            let c = (1 + costed) as usize;

            for i in (0..c).rev() {
                if lower_bound(target, i as i32) >= u_est { break; }
                let k = i as i32;
                let tgt = target - (k * (k + 1)).div_euclid(2);
                if (k + 1) + lower_bound(tgt, k) >= u_est { continue; }
                let curr = (k + 1) + sling(tgt, k);
                res = std::cmp::min(res, curr);
                if res == l_est { break; }
            }

            return res;
        }

        return sling(n, alpha(n)) - 1;

    }
}

fn main() {
    println!("res: {}", Solution::min_days(2));
    println!("res: {}", Solution::min_days(9));
    println!("res: {}", Solution::min_days(12));
    println!(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
}
