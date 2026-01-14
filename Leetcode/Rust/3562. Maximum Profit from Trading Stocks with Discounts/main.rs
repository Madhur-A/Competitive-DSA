



#[allow(unused_imports)]
// use itertools::Itertools;

/**
 * this is the most generic solution for this problem (the one which i came up with
 * is too esoteric *lol*). the fundamental thing about this is the traversal of a tree
 * especially in post-order, often when function stacks unwind they usually go back to
 * the state from they've originated (the so-called parent-node), effectively, losing
 * all the information they've gained (hence the storage is needed). this renders the
 * following concept, in which information is recorded into node. so when stacks unwind,
 * the decision logic (an obvious group-knapsack) has all the necessary information.
 *
**/

struct Solve {
    graph: Vec<Vec<usize>>,
    present: Vec<i32>,
    future: Vec<i32>,
    budget: usize,
}

impl Solve {
    fn dfs(&self, node: usize) -> (Vec<Vec<i32>>, usize) {
        let cost = self.present[node] as usize;
        let half = cost >> 1;

        let mut dp = vec![vec![0; self.budget + 1]; 2];
        let mut sub_profit = vec![vec![0; self.budget + 1]; 2];

        let mut accu_cost = cost;

        for &child in &self.graph[node] {
            let (sub_dp, sub_cost) = self.dfs(child);
            accu_cost += sub_cost;

            for i in (0..=self.budget).rev() {
                let limit = std::cmp::min(sub_cost, i);
                for pick in 0..=limit {
                    sub_profit[0][i] = std::cmp::max(sub_profit[0][i], sub_profit[0][i - pick] + sub_dp[0][pick]);
                    sub_profit[1][i] = std::cmp::max(sub_profit[1][i], sub_profit[1][i - pick] + sub_dp[1][pick]);

                }
            }
        }

        for i in 0..=self.budget {
            dp[0][i] = sub_profit[0][i];
            dp[1][i] = sub_profit[0][i];

            if i >= half {
                dp[1][i] = std::cmp::max(dp[1][i], sub_profit[1][i - half] + self.future[node] - half as i32);
            }

            if i >= cost {
                dp[0][i] = std::cmp::max(dp[0][i], sub_profit[1][i - cost] + self.future[node] - cost as i32);
            }
        }

        return (dp, accu_cost);
    }

    pub fn max_profit(n: usize, present: Vec<i32>, future: Vec<i32>, hierarchy: Vec<Vec<i32>>, budget: usize) -> i32 {
        let mut graph = vec![Vec::new(); n];
        for e in hierarchy {
            graph[(e[0] - 1) as usize].push((e[1] - 1) as usize);
        }

        let sol = Solve { graph, present, future, budget };
        let (dp, _) = sol.dfs(0);

        return dp[0][budget];
    }
}

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn max_profit(n: i32, present: Vec<i32>, future: Vec<i32>, hierarchy: Vec<Vec<i32>>, budget: i32) -> i32 {
        return Solve::max_profit(n as usize, present, future, hierarchy, budget as usize);
    }
}

fn main() {}
