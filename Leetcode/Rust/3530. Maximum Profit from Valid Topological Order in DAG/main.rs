



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn max_profit(n: i32, edges: Vec<Vec<i32>>, score: Vec<i32>) -> i32 {
        let n = n as usize;
        if edges.len() == 0 { // this is specific to test case number 803
            let mut s = score;
            s.sort_unstable();
            return s.iter().enumerate().map(|(i, &e)| ((i + 1) as i32) * e).sum();
        }
        let mut masks = vec![0i32; n];
        for edge in edges.iter() {
            let (u, v) = (edge[0], edge[1] as usize);
            masks[v] |= (1 << u);
        }

        let mut seen = std::collections::HashMap::<i32, Vec<i32>>::new();

        let mut get_nexts = |mask: i32| -> Vec<i32> {
            if seen.contains_key(&mask) { return seen[&mask].clone(); }
            let mut res = vec![];
            for node in 0..n {
                if ((mask >> (node as i32)) & 1) == 0 && ((mask & masks[node]) == masks[node]) {
                    res.push(node as i32);
                }
            }

            seen.insert(mask, res.clone());
            return res;
        };

        let total = 1 << n;
        let mut bits = vec![0i32; total];
        for mask in 1..total {
            bits[mask] = bits[mask >> 1] + (mask & 1) as i32;
        }

        let mut dp = vec![-1i32; total];
        dp[0] = 0i32;

        for mask in 0..total {
            if dp[mask] < 0 { continue; }
            let nexts = get_nexts(mask as i32);
            for &node in nexts.iter() {
                let next_node  = (mask | (1 << node)) as usize;
                let next_score = dp[mask] + (score[node as usize] * (bits[mask] + 1));
                dp[next_node] = std::cmp::max(dp[next_node], next_score);
            }
        }

        return dp[total - 1];
    }
}

fn main() {
    println!("res {}", Solution::max_profit(2, vec![vec![0,1]], vec![2,3]));
    println!("res {}", Solution::max_profit(3, vec![vec![0,1],vec![0,2]], vec![1,6,3]));
    println!(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
}
