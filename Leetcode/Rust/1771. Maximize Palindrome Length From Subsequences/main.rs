



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

// notice how the values (i.e., candidate answers) are tracked
// globally, but the decision is made locally. why? consider
// the case "aba" + "aba" = "abaaba": each partition is, by
// itself, a valid palindrome, but not necessarily valid
// under the problem’s constraints. of course, in this case
// the global and local considerations coincide, since
// "abaaba" is also a palindrome globally. however, if the
// partitions were "aba" and "xyz", then choosing "aba"
// would be incorrect according to the constraints, because
// "aba" is only a local palindrome.

impl Solution {
    #[allow(unused)]
    pub fn longest_palindrome(s: String, t: String) -> i32 {
        let n = s.len() + t.len();
        let m = s.len();
        let mut s = s.as_bytes().to_vec();
        s.extend(t.as_bytes().to_vec());

        let mut dp = vec![vec![0i32; n]; n];

        for i in 0..n {
            dp[i][i] = 1;
        }

        let mut res = 0i32;

        for ln in 2..=n {
            for left in 0..(n - ln + 1) {
                let right = left + ln - 1;
                if s[left] == s[right] && (ln < 3 || dp[left + 1][right - 1] != 0) {
                    dp[left][right] = dp[left + 1][right - 1] + 2;
                    res = match left < m && right + 1 > m {
                        true  => std::cmp::max(res, dp[left][right]),
                        false => res,
                    }
                } else {
                    dp[left][right] = std::cmp::max(dp[left + 1][right], dp[left][right - 1]);
                }
            }
        }

        return res;
    }
}

fn main() {}
