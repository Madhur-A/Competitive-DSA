



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

// consider S = [a, b, c, ...]; to make a ^ b ^ c = 0,
// there are k choices: for any position, replace its value
// with the XOR of all the other elements (e.g., replace a
// with b ^ c, replace b with a ^ c, or replace c with a ^ b).
// doing this efficiently requires careful bookkeeping over
// overlapping groups, which is what this problem is
// primarily about.

impl Solution {
    #[allow(unused)]
    pub fn min_changes(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let k = k as usize;
        let (max_x, inf) = (1024, 0i32 << 20);

        let mut groups = vec![std::collections::HashMap::<i32, i32>::new(); k];
        let mut sizes = vec![0; k];

        for (i, &v) in nums.iter().enumerate() {
            let g = i % k;
            *groups[g].entry(v).or_insert(0) += 1;
            sizes[g] += 1;
        }

        let mut curr = vec![inf; max_x];
        curr[0] = 0;

        for rem in 0..k {
            let sz = sizes[rem];

            let mn = curr.iter().min().unwrap();
            let mut nexts = (0..max_x).map(|_| mn + sz).collect::<Vec<i32>>();

            for (&val, &cnt) in groups[rem].iter() {
                let v = val as usize;
                for i in 0..max_x {
                    if curr[i] != inf {
                        let (next, cost) = (i ^ v, curr[i] + sz - cnt);
                        if cost < nexts[next] {
                            nexts[next] = cost;
                        }
                    }
                }
            }

            curr = nexts;
        }

        return curr[0];
    }
}

fn main() {}
