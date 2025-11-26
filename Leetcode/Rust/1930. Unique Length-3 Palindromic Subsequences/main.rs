



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        let mut first = vec![-1; 26];
        let mut  last = vec![-1; 26];

        let s_bytes = s.as_bytes();

        for (i, &ch) in s_bytes.iter().enumerate() {
            let idx = (ch - b'a') as usize;
            if first[idx] == -1 {
                first[idx] = i as i32;
            }
            last[idx] = i as i32;
        }

        let mut res = std::collections::HashSet::new();

        for i in 0..26 {
            if first[i] != -1 && first[i] != last[i] {
                for mid in (first[i] + 1) as usize..last[i] as usize {
                    res.insert((i as u8 + b'a', s_bytes[mid]));
                }
            }
        }

        res.len() as i32
    }
}

fn main() {}
