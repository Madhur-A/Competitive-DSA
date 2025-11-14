



struct Solution;

impl Solution {
    pub fn range_add_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = n as usize;
        let (r, c) = (n + 2, n + 2);
        let mut grid: Vec<Vec<i32>> = vec![vec![0; c]; r];

        for query in queries {
            let [i, j, h, k]: [i32; 4] = query.try_into().unwrap();
            let (i, j, h, k) = (i as usize, j as usize, h as usize, k as usize);
            grid[i + 1][j + 1] += 1;
            grid[h + 2][k + 2] += 1;
            grid[i + 1][k + 2] -= 1;
            grid[h + 2][j + 1] -= 1;
        }

        for i in 1..=n {
            for j in 1..=n {
                grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
            }
        }

        grid[1..=n].iter().map(|row| row[1..=n].to_vec()).collect()
    }
}

fn main() {}
