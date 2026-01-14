



#[allow(unused_imports)]
// use itertools::Itertools;

struct SegTree {
    n: usize,
    t: Vec<i32>,
    l: Vec<i32>,
}

// this calls for the combination of prefix and max in range methods
// with cooridnate compression on inputs along with lazy propagation

#[allow(unused)]
impl SegTree {
    fn new(n: usize) -> Self {
        return Self {
            n: n,
            t: vec![0i32; 4 * n],
            l: vec![0i32; 4 * n],
        };
    }

    fn push(&mut self, node: usize) {
        let curr = self.l[node];
        if curr > 0 {
            for i in [1, 2] {
                let child = 2*node + i;
                self.t[child] = std::cmp::max(self.t[child], curr);
                self.l[child] = std::cmp::max(self.l[child], curr);
            }
            self.l[node] = 0;
        }
    }

    fn update(&mut self, left: usize, right: usize, value: i32) {
        return self.update_exec(0, 0, self.n - 1, left, right, value);
    }

    fn update_exec(
        &mut self,
        node: usize,
        start: usize,
        end: usize,
        left: usize,
        right: usize,
        value: i32,
    ) {
        if right < start || end < left {
            return;
        }
        if left <= start && end <= right {
            self.t[node] = std::cmp::max(self.t[node], value);
            self.l[node] = std::cmp::max(self.l[node], value);
            return;
        }
        self.push(node);
        let mid = start + ((end - start) >> 1);
        self.update_exec(2*node + 1, start, mid, left, right, value);
        self.update_exec(2*node + 2, mid + 1, end, left, right, value);
        self.t[node] = std::cmp::max(self.t[2*node + 1], self.t[2*node + 2]);
    }

    fn find(&mut self, left: usize, right: usize) -> i32 {
        return self.find_exec(0, 0, self.n - 1, left, right);
    }

    fn find_exec(
        &mut self,
        node: usize,
        start: usize,
        end: usize,
        left: usize,
        right: usize,
    ) -> i32 {
        if right < start || end < left {
            return 0i32;
        }
        if left <= start && end <= right {
            return self.t[node];
        }

        self.push(node);
        let mid = start + ((end - start) >> 1);
        return std::cmp::max(
            self.find_exec(2*node + 1, start, mid, left, right),
            self.find_exec(2*node + 2, mid + 1, end, left, right),
        );
    }
}

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn falling_squares(positions: Vec<Vec<i32>>) -> Vec<i32> {
        let n = positions.len();
        let mut ranges = Vec::<i32>::new();

        for position in positions.iter() {
            ranges.push(position[0]);
            ranges.push(position[0] + position[1]);
        }
        ranges.sort();
        ranges.dedup();

        let mut indices = ranges.into_iter().enumerate().fold(
            std::collections::HashMap::<i32, i32>::new(),
            |mut g, (i, num)| {
                g.insert(num, i as i32);
                g
            },
        );
        let mut st = SegTree::new(indices.len());
        let mut res = vec![0i32; n];
        let mut global_max = 0i32;

        for (i, position) in positions.iter().enumerate() {
            let (left, right, height) = (position[0], position[0] + position[1], position[1]);
            let h = *indices.get(&left).unwrap_or(&0) as usize;
            let k = *indices.get(&right).unwrap_or(&0) as usize - 1usize;
            let local_max = st.find(h, k) + height;
            global_max = std::cmp::max(local_max, global_max);
            res[i] = global_max;
            st.update(h, k, local_max);
        }

        return res;
    }
}

fn main() {}
