



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn shortest_palindrome(s: String) -> String {
        let n = s.len();
        if n == 0 { return s; }

        let sc = s.as_bytes().to_vec();

        let mut m = 0usize;

        for i in (0..n).rev() {
            if sc[0] == sc[i] {
                let mut left = 0;
                let mut right = i;
                while left < right && sc[left] == sc[right] {
                    left += 1;
                    right -= 1;
                }
                if left >= right {
                    m = i + 1;
                    break;
                }
            }
        }

        let suffix = (&s[m..n]).chars().rev().collect::<String>();

        return suffix + &s;
    }
}

fn main() {
    println!("res: {}", Solution::shortest_palindrome("abbacde".to_string()));
    println!("res: {}", Solution::shortest_palindrome("aaaaa".to_string()));
}
