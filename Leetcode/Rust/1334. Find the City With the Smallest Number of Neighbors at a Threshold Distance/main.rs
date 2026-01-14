



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    const INF: i32 = 1E9 as i32;

    pub fn find_the_city(n: i32, edges: Vec<Vec<i32>>, distance_threshold: i32) -> i32 {
        let n = n as usize;
        let mut g = vec![Vec::<(usize, i32)>::new(); n];

        for edge in edges {
            let (u, v, w) = (edge[0] as usize, edge[1] as usize, edge[2]);
            g[u].push((v, w));
            g[v].push((u, w));
        }

        let mut t = std::collections::BinaryHeap::<(i32, usize)>::new();
        let mut max_count = n;
        let mut res = 0usize;

        for i in 0..n {
            t.push((0i32, i));
            let mut distances = vec![Self::INF; n];
            distances[i] = 0i32;

            while let Some((curr_distance, node)) = t.pop() {
                let curr_distance = -curr_distance;
                for &(child, weight) in &g[node] {
                    if distances[child] > curr_distance + weight {
                        distances[child] = curr_distance + weight;
                        t.push((-distances[child], child));
                    }
                }
            }

            let count = distances
                .into_iter()
                .filter(|&distance| distance <= distance_threshold)
                .count();

            if count <= max_count {
                max_count = count;
                res = std::cmp::max(res, i);
            }
        }

        return res as i32;
    }
}

fn main() {
    // println!("res: {}", Solution::find_the_city(4, vec![vec![0,1,3],vec![1,2,1],vec![1,3,4],vec![2,3,1]], 4));
}
