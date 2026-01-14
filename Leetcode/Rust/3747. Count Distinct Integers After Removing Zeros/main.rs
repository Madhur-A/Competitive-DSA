



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn select_if<T>(condition: bool, a: T, b: T) -> T {
        return if condition { a } else { b };
    }

    pub fn count_distinct(n: i64) -> i64 {
        let s = n.to_string();
        let length = s.len();

        let a = 9i64;
        let mut skip = false;

        let mut res = 0i64;
        for (i, ch) in s.chars().enumerate() {
            let digit = ch.to_digit(10).unwrap() as i64;

            if digit == 0 {
                skip = true;
            }

            res += Self::select_if(i < length - 1, a.pow((i + 1) as u32), 0i64);
            res += Self::select_if(skip, 0i64, (digit - 1) * a.pow((length - i - 1) as u32));
        }

        return res + Self::select_if(skip, 0i64, 1i64);
    }
}

fn main() {}
