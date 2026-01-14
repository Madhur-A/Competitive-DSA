



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct SegTree {
    n: usize,
    t: Vec<i32>,
}

impl SegTree {
    #[allow(unused)]
    fn new(n: usize) -> Self {
        return Self { n: n, t: vec![0i32; 4*n] };
    }

    #[allow(unused)]
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

    #[allow(unused)]
    fn find(&self, left: usize, right: usize) -> i32 {
        if (left <= right) {
            return self._find(0, 0, self.n - 1, left, right);
        } else {
            return 0i32;
        }
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
    pub fn count_range_sum(nums: Vec<i32>, lower: i32, upper: i32) -> i32 {
        let pfx = std::iter::once(0i64)
            .chain(nums.iter().map(|&num| num as i64))
            .scan(0i64, |acc, num| {
                *acc += num;
                Some(*acc)
            })
            .collect::<Vec<i64>>();

        let mut res = 0i32;
        let mut qfx = pfx.iter().fold(pfx.clone(), |mut pfx, &prefix| {
            pfx.push(prefix - lower as i64);
            pfx.push(prefix - upper as i64);
            pfx
        });
        qfx.sort();
        qfx.dedup();

        let mut st = SegTree::new(qfx.len());

        for &prefix in pfx.iter() {
            let l = qfx.partition_point(|&e| e < prefix - upper as i64);
            let r = qfx.partition_point(|&e| e < prefix - lower as i64 + 1i64);
            res += st.find(l, r.saturating_sub(1));
            st.update(qfx.partition_point(|&e| e < prefix), 1);
        }

        return res;
    }
}

fn main() {}
