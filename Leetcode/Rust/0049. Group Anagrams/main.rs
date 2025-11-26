#[allow(unused_imports)]
// use itertools::Itertools;
use std::collections::HashMap;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        strs.into_iter()
            .fold(
                HashMap::<String, Vec<String>>::new(),
                |mut g, curr_string| {
                    let mut key = curr_string.chars().collect::<Vec<char>>();
                    key.sort_unstable();
                    g.entry(key.into_iter().collect::<String>())
                        .or_default()
                        .push(curr_string);
                    g
                },
            )
            .into_values()
            .collect()
    }
}

fn main() {}
