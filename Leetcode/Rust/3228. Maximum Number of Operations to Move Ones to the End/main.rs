



struct Solution;

impl Solution {
    fn max_operations(s: String) -> i32 {
        s.trim_end_matches('1')
        .chars()
        .rev()
        .fold((0, 0, false), |(res, k, in_zero), ch| match ch {
            '0' => if !in_zero { (res, k + 1, true) } else { (res, k, true) },
            '1' => (res + k, k, false),
             _  => (res, k, in_zero),
        }).0
    }
}

// 1001101
// trim and iterate from the right
// if we encounter '0' continue
// if we encounter '1' then res += k
// if we encounter '0' again continue and k += 1 (once)

fn main() {
    // Solution::max_operations(String::from("1001101"));
}
