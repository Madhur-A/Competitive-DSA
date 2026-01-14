



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

/*
curtailing solution-space, instead of finding the proverbial
sequential logic to ascertain the optimality. not exactly
satisfactory but works nonetheless `(26 x 26)`.
*/

impl Solution {
    #[allow(unused)]
    pub fn largest_variance(s: String) -> i32 {
        let n = s.len();
        let sb = s.as_bytes();

        let mut res = 0i32;

        for fst in 'a'..='z' {
            for snd in 'a'..='z' {
                if fst != snd {
                    // make-shift Kadane over `s`
                    let (mut freq, mut maxx) = (0i32, -(n as i32)); // freq, maximum
                    for curr in s.chars() {
                        if curr == fst { freq += 1i32; maxx += 1i32; }
                        if curr == snd { maxx = std::cmp::max(maxx - 1i32, freq - 1i32); freq = 0i32; }
                        res = std::cmp::max(res, maxx);
                    }
                }
            }
        }

        return res;
    }
}

fn main() {}
