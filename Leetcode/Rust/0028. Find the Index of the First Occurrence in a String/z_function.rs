



#[allow(unused_imports)]
// use itertools::Itertools;

// Z-Function
// Quasi-Functional Variant

// Author: Nishizumi

// n.b. ~ not meant for production!!

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn zf(s: &[u8]) -> Vec<usize> {
        (1..s.len()).fold((&mut vec![0usize; s.len()], 0usize, 0usize), |(z, left, right), i| {
            match i > right {
                true  => {
                    let (mut l, mut r) = (i, i);
                    while r < s.len() && s[r - l] == s[r] { r += 1; }
                    z[i] = r - l;
                    (z, l, r - 1)
                },
                false => {
                    match z[i - left] < right - i + 1 {
                        true  => { z[i] = z[i - left]; (z, left, right) },
                        false => {
                            let (mut l, mut r) = (i, right);
                            while r < s.len() && s[r - l] == s[r] { r += 1; }
                            z[i] = r - l;
                            (z, l, r - 1)
                        }
                    }
                }
            }
        }).0.to_vec()
    }

    #[allow(unused)]
    pub fn str_str(haystack: String, needle: String) -> i32 {
        let (n, m) = (needle.len() + 1, needle.len() + haystack.len() + 1);
        let s = needle + "#" + &haystack;
        let z = Self::zf(s.as_bytes());

        z[n..].iter().position(|&e| e >= (n - 1)).map(|found| found as i32).unwrap_or(-1)
    }
}

fn main() {}
