



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

// runtime exceeds 1 second (1164 ms)! 

impl Solution {
    #[allow(unused)]
    pub fn min_cost(grid: Vec<Vec<i32>>, k: i32) -> i32 {
        let (r, c, k) = (grid.len(), grid[0].len(), k as usize);
        let inf = i32::MAX >> 1;

        let max_possible = *grid.iter().flatten().max().unwrap_or(&0) as usize + 1;

        let mut dp = vec![vec![vec![inf; k + 1]; c]; r];
        let mut t = std::collections::BinaryHeap::<(i32, usize, usize)>::new();

        let mut indices = vec![Vec::<usize>::new(); max_possible];
        for i in 0..r {
            for j in 0..c {
                indices[grid[i][j] as usize].push(i * c + j);
            }
        }

        let mut dj_values = vec![vec![inf; max_possible]; k + 1];
        let mut suffix_mins = vec![vec![inf; max_possible]; k + 1];

        dp[0][0][0] = 0;
        t.push((0, 0, 0));

        // initial zero-cost jumps from (0,0)
        if k > 0 {
            let start_val = grid[0][0] as usize;
            for v in 0..=start_val {
                for &pos in &indices[v] {
                    let (x, y) = (pos / c, pos % c);
                    dp[x][y][1] = 0;
                    t.push((0, pos, 1));
                }
            }
            dj_values[0][start_val] = 0;
        }

        while let Some((neg_cost, pos, rem)) = t.pop() {
            let cost = -neg_cost;
            let (i, j) = (pos / c, pos % c);

            if cost > dp[i][j][rem] {
                continue;
            }

            let node = grid[i][j] as usize;

            // value-based propagation
            if cost < dj_values[rem][node] {
                dj_values[rem][node] = cost;

                let mut v = node;
                while v > 0 && cost < suffix_mins[rem][v] {
                    suffix_mins[rem][v] = cost;

                    if rem + 1 <= k {
                        for &next in &indices[v] {
                            let (x, y) = (next / c, next % c);
                            if cost < dp[x][y][rem + 1] {
                                dp[x][y][rem + 1] = cost;
                                t.push((-cost, next, rem + 1));
                            }
                        }
                    }
                    v -= 1;
                }
            }

            // handle value 0 separately
            if cost < suffix_mins[rem][0] {
                suffix_mins[rem][0] = cost;

                if rem + 1 <= k {
                    for &next in &indices[0] {
                        let (x, y) = (next / c, next % c);
                        if cost < dp[x][y][rem + 1] {
                            dp[x][y][rem + 1] = cost;
                            t.push((-cost, next, rem + 1));
                        }
                    }
                }
            }

            // grid transitions
            if j + 1 < c {
                let ncost = cost + grid[i][j + 1];
                if ncost < dp[i][j + 1][rem] {
                    dp[i][j + 1][rem] = ncost;
                    t.push((-ncost, i * c + j + 1, rem));
                }
            }

            if i + 1 < r {
                let ncost = cost + grid[i + 1][j];
                if ncost < dp[i + 1][j][rem] {
                    dp[i + 1][j][rem] = ncost;
                    t.push((-ncost, (i + 1) * c + j, rem));
                }
            }
        }

        return dp[r - 1][c - 1].iter().min().copied().unwrap_or(0);
    }
}

fn main() {
    println!("res: 46 ?= {}", Solution::min_cost(vec![vec![6,7,1,20,11],vec![4,5,18,23,28]], 3));
    // println!("res:  9 ?= {}", Solution::min_cost(vec![vec![1,2],vec![2,3],vec![3,4]], 1));
    // println!("res:  7 ?= {}", Solution::min_cost(vec![vec![1,3,3],vec![2,5,4],vec![4,3,5]], 2));
    println!(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
}
