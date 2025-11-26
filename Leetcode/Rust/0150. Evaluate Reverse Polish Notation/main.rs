



#[allow(unused_imports)]
use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        tokens.into_iter().fold(Vec::new(), |mut res, token| {
            if let Ok(n) = token.parse::<i32>() {
                res.push(n);
            } else {
                let b = res.pop().unwrap();
                let a = res.pop().unwrap();
                res.push(match token.as_str() {
                    "+" => a + b,
                    "-" => a - b,
                    "*" => a * b,
                    "/" => a / b,
                     _  => unreachable!(),
                });
            }; res
        }).pop().unwrap()
    }
}

fn main() {}
