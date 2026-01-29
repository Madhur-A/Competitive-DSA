



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

// just optimizations are mine (the algorithm is NOT)
// current run time (with my unsteady connection) ~ 92 ms

impl Solution {
    #[allow(unused)]
    pub fn min_cost(grid: Vec<Vec<i32>>, k: i32) -> i32 {
        let (r, c, k) = (grid.len(), grid[0].len(), k as usize);
        let total = r * c;
        let inf = i32::MAX >> 1;

        let grid = grid.iter().flatten().map(|&e| e).collect::<Vec<i32>>();

        let mut values =
            grid.iter().enumerate().fold(Vec::<(i32, usize)>::new(), |mut acc, (i, &elem)| {
                acc.push((elem, i)); acc
            });

        let mut dp = vec![vec![inf; total]; k + 1];

        dp[0][0] = 0i32;
        values.sort_unstable_by_key(|&v| -v.0);
        let max_possible = values[0].0 as usize + 1;

        for i in 1..r { dp[0][i*c] = dp[0][(i - 1)*c] + grid[i*c + 0]; }
        for j in 1..c { dp[0][j]   = dp[0][j - 1]     + grid[0*c + j]; }

        for curr in 1..total {
            let (i, j) = (curr / c, curr % c);
            let up     = (i.saturating_sub(1))*c + j;
            let left   = i*c + (j.saturating_sub(1));
            dp[0][curr] =
                    std::cmp::min(dp[0][up],
                                  dp[0][left]) + grid[curr];
        }

        for t in 1..=k {
            let (have, _) =
                values.iter().fold((vec![inf; max_possible], inf), |(mut have, mut res), &(_, curr)| {
                    let node = grid[curr] as usize;
                    res = std::cmp::min(res, dp[t - 1][curr]);
                    have[node] = res;
                    (have, res)
                });

            for curr in 0..total {
                let (i, j) = (curr / c, curr % c);
                let up     = (i.saturating_sub(1))*c + j;
                let left   = i*c + (j.saturating_sub(1));

                dp[t][curr] = have[grid[curr] as usize];

                dp[t][curr] = std::cmp::min(dp[t][curr],
                                            dp[t][up]   + grid[curr]);
                dp[t][curr] = std::cmp::min(dp[t][curr],
                                            dp[t][left] + grid[curr]);
            }
        }


        return dp[k][total - 1];
    }
}

fn main() {
    println!("res: 46 ?= {}", Solution::min_cost(vec![vec![6,7,1,20,11],vec![4,5,18,23,28]], 3));
    // println!("res:  9 ?= {}", Solution::min_cost(vec![vec![1,2],vec![2,3],vec![3,4]], 1));
    // println!("res:  7 ?= {}", Solution::min_cost(vec![vec![1,3,3],vec![2,5,4],vec![4,3,5]], 2));
    println!(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
}
