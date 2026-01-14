



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn count_covered_buildings(n: i32, buildings: Vec<Vec<i32>>) -> i32 {
        let mut g = std::collections::HashMap::<i32, Vec<i32>>::new();
        let mut h = std::collections::HashMap::<i32, Vec<i32>>::new();

        for building in buildings.iter() {
            let (x, y) = (building[0], building[1]);
            g.entry(x).or_insert_with(Vec::new).push(y);
            h.entry(y).or_insert_with(Vec::new).push(x);
        }

        for vec in g.values_mut() {
            vec.sort_unstable();
        }
        for vec in h.values_mut() {
            vec.sort_unstable();
        }

        let mut res = 0;

        for (&y, xs) in h.iter() {
            if xs.len() > 1 {
                for x in &xs[1..xs.len() - 1] {
                    if let Some(v) = g.get(&x) {
                        let found = v.partition_point(|&e| e < y);
                        if found < v.len() - 1 && found > 0 {
                            res += 1;
                        }
                    }
                }
            }
        }

        return res;
    }
}

fn main() {}
