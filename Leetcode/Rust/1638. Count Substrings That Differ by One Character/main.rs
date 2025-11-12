



#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn count_substrings(s: String, t: String) -> i32 {
        let (r, c) = (s.len(), t.len());
        let (s, t): (Vec<char>, Vec<char>) = (s.chars().collect(), t.chars().collect());

        let (mut res, mut diff, mut k) = (0, 0, 0);

        for i in 0..r {
            for j in 0..c {
                k = 0;
                diff = 0;
                while i + k < r && j + k < c && diff < 2 { // expanding radius technique
                    if s[i + k] != t[j + k] {
                        diff += 1;
                    }
                    if diff == 1 { res += 1; }
                    k += 1;
                }
            }
        }

        return res;
    }
}

fn main() {}
