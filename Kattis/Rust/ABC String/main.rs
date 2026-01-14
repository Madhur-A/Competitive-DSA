



// https://open.kattis.com/problems/abcstring

#[allow(unused_imports)]
use std::io::{self, BufRead};

fn main() {
    io::stdin().lock().lines().for_each(|line| {
        println!(
            "{}",
            line.unwrap()
                .trim()
                .as_bytes()
                .iter()
                .map(|e| (e - ('A' as u8)) as usize)
                .fold(([0, 0, 0], 0), |(mut seen, res), i| {
                    seen[i] += 1;
                    let fin = seen.iter().min().unwrap();
                    (seen, res.max(seen.iter().map(|e| e - fin).max().unwrap()))
                })
                .1
        );
    });
}
