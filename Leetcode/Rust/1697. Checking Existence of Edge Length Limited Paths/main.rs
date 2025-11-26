



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn distance_limited_paths_exist(n: i32, mut edge_list: Vec<Vec<i32>>, mut queries: Vec<Vec<i32>>) -> Vec<bool> {
        let n = n as usize;

        let mut roots: Vec<usize> = (0..n).collect();
        let mut ranks: Vec<i32> = vec![0; n];

        fn find(roots: &mut [usize], i: usize) -> usize {
            if roots[i] != i {
                roots[i] = find(roots, roots[i]);
            }
            roots[i]
        }

        fn union(roots: &mut [usize], ranks: &mut [i32], a: usize, b: usize) {
            let ra = find(roots, a);
            let rb = find(roots, b);
            if ra != rb {
                if ranks[ra] <= ranks[rb] {
                    roots[ra] = rb;
                    ranks[rb] = ranks[rb] + (if ranks[ra] == ranks[rb] { 1 } else { 0 });
                } else if ranks[ra] > ranks[rb] {
                    roots[rb] = ra;
                }
            }
        }

        edge_list.sort_unstable_by_key(|e| e[2]);
        let mut qs: Vec<(i32, i32, i32, usize)> = queries
            .iter()
            .enumerate()
            .map(|(i, q)| (q[0], q[1], q[2], i))
            .collect();

        qs.sort_unstable_by_key(|q| q.2);

        let mut res = vec![false; queries.len()];
        let mut i = 0;

        for &(p, q, limit, qi) in &qs {
            // Add edges with weight < limit
            while i < edge_list.len() && edge_list[i][2] < limit {
                let (u, v) = (edge_list[i][0] as usize, edge_list[i][1] as usize);
                union(&mut roots, &mut ranks, u, v);
                i += 1;
            }

            res[qi] = find(&mut roots, p as usize) == find(&mut roots, q as usize);
        }

        return res;
    }
}

fn main() {}
