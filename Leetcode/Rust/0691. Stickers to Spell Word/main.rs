



#[allow(unused_imports)]
use std::collections::HashMap;
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn min_stickers(stickers: Vec<String>, target: String) -> i32 {
        // suppose we convert each word to a freq map for [1..26]
        // and then use unbounded knapsack

        let to_freq_array = |s: &str| -> [i32; 26] {
            let mut freq = [0i32; 26];
            s.as_bytes().iter().map(|e| (e - ('a' as u8)) as usize).for_each(|e| freq[e] += 1);
            return freq;
        };

        let dest = to_freq_array(&target);
        let mut have = stickers.iter().fold(Vec::<[i32;26]>::new(), |mut acc, sticker| {
            acc.push(to_freq_array(sticker)); acc
        });
        have.retain(|e| (0..26).any(|i| e[i] > 0 && dest[i] > 0)); // only useful candidates

        fn dfs(have: &Vec<[i32;26]>, dest: &[i32;26], seen: &mut HashMap<[i32;26], i32>) -> i32 {
            let mut res = i32::MAX >> 1;
            if let Some(&found) = seen.get(dest) {
                return found;
            }

            if dest.iter().all(|&e| e == 0) { return 0i32; }
            let mut first = dest.iter().position(|&e| e != 0).unwrap(); // the upper condition guarantees fail-safe

            for candidate in have.iter() {
                if candidate[first] != 0 {
                    let mut new_dest = [0i32; 26];
                    for i in 0..26 {
                        if candidate[i] < dest[i] {
                            new_dest[i] = dest[i] - candidate[i];
                        }
                    }
                    res = std::cmp::min(res, 1 + dfs(&have, &new_dest, seen));
                }
            }

            seen.insert(dest.clone(), res);
            return res;
        }

        let res = dfs(&have, &dest, &mut HashMap::<[i32;26], i32>::new());

        return
            if (res >= (i32::MAX >> 1)) { -1 } else { res };
    }
}

fn main() {
    println!("res: {}", Solution::min_stickers(vec!["with".to_string(),"example".to_string(),"science".to_string()], "thehat".to_string()));
    println!("res: {}", Solution::min_stickers(vec!["notice".to_string(),"possible".to_string()], "basicbasic".to_string()));
    println!(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
}
