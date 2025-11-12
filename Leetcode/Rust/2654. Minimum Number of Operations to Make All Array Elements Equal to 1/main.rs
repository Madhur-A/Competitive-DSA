



#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn gcd(a: i32, b: i32) -> i32 {
        if b == 0 { a.abs() } else { Self::gcd(b, a % b) }
    }

    #[allow(unused)]
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        // see if possible
        let total_gcd = nums.iter().copied().reduce(|a, b| Self::gcd(a, b)).unwrap();
        // if not, then
        if total_gcd > 1 { return -1; }

        // count 1's, if they exist
        if nums.contains(&1) {
            let ones = nums.iter().filter(|&&x| x == 1).count();
            return (n - ones) as i32;
        }

        // otherwise
        let mut min_len = 1 << 30;
        for i in 0..n {
            let mut g = nums[i];
            for j in i..n {
                g = Self::gcd(g, nums[j]);
                if g == 1 {
                    min_len = min_len.min(j - i + 1);
                    break;
                }
            }
        }

        return (n + min_len - 2) as i32;
    }
}

fn main() {}
