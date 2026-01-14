



use std::io::{self, BufRead};

// https://www.hackerrank.com/challenges/string-similarity/problem
// Z-Algorithm (Procedural Variant)

#[allow(unused)]
struct Solution;

#[allow(unused)]
impl Solution {
    fn z_function(s: &[u8]) -> i64 {
        let n = s.len();
        let (mut left, mut right) = (0usize, 0usize);
        let mut z = vec![0i64; n];
        let mut res = n as i64;

        for i in 0..n {
            if i > right {
                left = i; right = i;
                while right < n && s[right - left] == s[right] {
                    right += 1;
                }
                z[i] = (right - left) as i64;
                res += z[i];
                right -= 1;
            } else {
                let mirrored_index = i - left;
                if (z[mirrored_index] as usize) < right - i + 1 {
                    z[i] = z[mirrored_index];
                    res += z[i];
                } else {
                    left = i;
                    while right < n && s[right - left] == s[right] {
                        right += 1;
                    }
                    z[i] = (right - left) as i64;
                    res += z[i];
                    right -= 1;
                }
            }
        }

        return res;
    }
}

fn main() {
    io::stdin().lock().lines().skip(1).for_each(|line| {
        println!("{}", Solution::z_function(line.unwrap().trim().as_bytes()));
    });
}
