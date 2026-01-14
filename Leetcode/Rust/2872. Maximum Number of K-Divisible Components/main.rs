



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn max_k_divisible_components(n: i32, edges: Vec<Vec<i32>>, values: Vec<i32>, k: i32) -> i32 {
        let n = n as usize;
        let k = k as usize;
        if n == 1 { return 1; }

        let mut g = vec![Vec::<usize>::new(); n];
        let mut degs = vec![0i32; n];

        for edge in edges {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            g[u].push(v); g[v].push(u);
            degs[u] += 1;
            degs[v] += 1;
        }

        let mut t = std::collections::VecDeque::<usize>::new();
        let mut visited = vec![false; n];
        (0..n).into_iter().for_each(|node| if degs[node] == 1 { t.push_back(node); });
        let mut sums = values.into_iter().map(|e| e as i64).collect::<Vec<i64>>();

        let mut ans = 0i32;
        while let Some(node) = t.pop_front() {
            visited[node] = true;
            if sums[node].rem_euclid(k as i64) == 0 { ans += 1; }
            for &child in g[node].iter() {
                if !visited[child] {
                    sums[child] += sums[node]; // child += parent
                    degs[child] -= 1;
                    if degs[child] == 1 {
                        t.push_back(child);
                    }
                }
            }
        }

        return ans;
    }
}

fn main() {}
