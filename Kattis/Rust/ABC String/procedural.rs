



// https://open.kattis.com/problems/abcstring

#[allow(unused_imports)]
use std::io::{self, BufRead};

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn solve(s: &[u8]) {
        let n = s.len();
        let offset = 'A' as u8;

        let mut seen = [0,0,0];
        let mut res = 0i32;

        for i in 0..n {
            let c = (s[i] - offset) as usize;
            seen[c] += 1;
            let fin = seen.iter().min().unwrap();
            res = std::cmp::max(res, seen.iter().map(|e| e - fin).max().unwrap());
        }

        println!("{}", res);
    }
}

fn main() {
    io::stdin().lock().lines().for_each(|line| {
        let input = line;
        Solution::solve(input.unwrap().trim().as_bytes());
    });
}
