



#[allow(unused_imports)]
use itertools::Itertools;

struct SegTree {
    n: usize,
    t: Vec<i32>,
}

impl SegTree {
    fn new(size: usize) -> Self {
        return Self {
            n: size,
            t: vec![0i32; 4*size],
        };
    }

    fn update(&mut self, index: usize, value: i32) {
        return self._update(0, 0, self.n - 1, index, value);
    }

    fn _update(&mut self, node: usize, start: usize, end: usize, index: usize, value: i32) {
        if start == end {
            self.t[node] += value;
        } else {
            let mid = start + ((end - start) >> 1);
            if index <= mid {
                self._update(2*node + 1, start, mid, index, value);
            } else {
                self._update(2*node + 2, mid + 1, end, index, value);
            }
            self.t[node] = self.t[2*node + 1] + self.t[2*node + 2];
        }
    }

    fn find(&self, left: usize, right: usize) -> i32 {
        return self._find(0, 0, self.n - 1, left, right);
    }

    fn _find(&self, node: usize, start: usize, end: usize, left: usize, right: usize) -> i32 {
        if right < start || end < left {
            return 0i32;
        }
        if left <= start && end <= right {
            return self.t[node];
        }
        let mid = start + ((end - start) >> 1);
        return
            self._find(2*node + 1, start, mid, left, right) +
            self._find(2*node + 2, mid + 1, end, left, right);
    }
}

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn reverse_pairs(numbers: Vec<i32>) -> i32 {
        let mut nums = numbers
            .iter()
            .collect::<std::collections::HashSet<&i32>>()
            .iter()
            .map(|&&e| e as i64)
            .collect::<Vec<i64>>();

        nums.extend(nums.iter().map(|&e| (e as i64) << 1).collect::<Vec<i64>>());

        let indices = nums
            .into_iter()
            .sorted() // this seqeunce depends upon `itertools`. can be replace via
            .dedup()  // two function calls viz., `nums.sort(); nums.dedup();` as done
            .fold(    // in previous programs of similar nature.
                (std::collections::HashMap::<i64, usize>::new(), 1usize),
                |(mut g, count), num| {
                    *g.entry(num).or_insert(count);
                    (g, count + 1)
                },
            )
            .0;

        let m = indices.len();
        let mut res = 0i32;
        let mut st = SegTree::new(m + 1);

        for &num in numbers.iter() {
            let num = num as i64;
            let double = num << 1;
            let found = *indices.get(&double).unwrap_or(&0);
            res += st.find(found + 1, m);
            st.update(*indices.get(&num).unwrap_or(&0), 1);
        }

        return res;
    }
}

fn main() {}
