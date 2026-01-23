



#[allow(unused_imports)]
// use itertools::Itertools;

// KMP Algorithm
// Quasi-Functional Variant

// Author: Nishizumi

// n.b. ~ not meant for production!!

#[allow(unused)]
struct Matcher<'a> {
    needle: &'a [u8],
    haystack: &'a [u8],
    lps: Vec<usize>,
}

#[allow(unused)]
impl<'a> Matcher<'a> {
    pub fn new(needle: &'a str, haystack: &'a str) -> Self {
        return
            Matcher {
                needle: needle.as_bytes(),
                haystack: haystack.as_bytes(),
                lps: Self::lps_array(needle.as_bytes()),
            };
    }

    pub fn lps_array(needle: &[u8]) -> Vec<usize> {
        (1..needle.len())
            .fold((&mut vec![0usize; needle.len()], 0usize), |(res, j), i| match needle[i] == needle[j] {
                true  => { res[i] = j + 1; (res, j + 1) }
                false => {
                    let mut j_root = j;
                    while j_root > 0 && needle[i] != needle[j_root] { j_root = res[j_root - 1]; }
                    if needle[j_root] == needle[i] { j_root += 1; }
                    res[i] = j_root;
                    (res, j_root)
                }
            }).0.to_vec()
    }

    pub fn first_match(&self) -> i32 {
        return self.rx(0usize, 0usize);
    }

    fn rx(&self, i: usize, j: usize) -> i32 {
        match i < self.haystack.len() {
            false => -1,
            true  => match self.needle[j] == self.haystack[i] {
                true  => {
                    if j + 1 == self.needle.len() {
                        (i - j) as i32 /* can store all matches */
                    } else {
                        self.rx(i + 1, j + 1)
                    }
                }
                false => {
                    if j != 0 {
                        self.rx(i, self.lps[j - 1] as usize)
                    } else {
                        self.rx(i + 1, 0)
                    }
                }
            }
        }
    }
}

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn str_str(haystack: String, needle: String) -> i32 {
        let m = Matcher::new(&needle, &haystack);

        return m.first_match();
    }
}

fn main() {}
