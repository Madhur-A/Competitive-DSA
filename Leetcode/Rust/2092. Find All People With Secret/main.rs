



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn find_all_people(n: i32, meetings: Vec<Vec<i32>>, first_person: i32) -> Vec<i32> {
        let n = n as usize;
        let mut g = vec![Vec::<(usize, i32)>::new(); n];

        meetings.iter().for_each(|meeting| {
            let (u, v, time) = (meeting[0] as usize, meeting[1] as usize, meeting[2]);
            g[u].push((v, time));
            g[v].push((u, time));
        });

        let mut t = std::collections::BinaryHeap::<(std::cmp::Reverse<i32>, usize)>::new();
        let mut timings = vec![i32::MAX; n];

        timings[0] = 0;
        timings[first_person as usize] = 0;

        t.push((std::cmp::Reverse(0i32), 0usize));
        t.push((std::cmp::Reverse(0i32), first_person as usize));

        let mut res = Vec::<i32>::new();

        while let Some((std::cmp::Reverse(node_time), node)) = t.pop() {
            if node_time <= timings[node] {
                res.push(node as i32);
                for &(child, child_time) in g[node].iter() {
                    if node_time <= child_time && timings[child] > child_time {
                        timings[child] = child_time;
                        t.push((std::cmp::Reverse(child_time), child));
                    }
                }
            }
        }

        return res;
        // return timings.iter().enumerate().filter(|(_, value)| **value != i32::MAX).map(|(index, _)| index as i32).collect::<Vec<i32>>();
    }
}

fn main() {}
