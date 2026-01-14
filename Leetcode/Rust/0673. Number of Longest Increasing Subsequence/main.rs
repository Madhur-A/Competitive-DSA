



#[allow(unused_imports)]
// use itertools::Itertools;

struct SegTree {
    n: usize,
    t: Vec<(usize, usize)>, // (max_len, count_of_all_subsequences_having_max_len)
}

impl SegTree {
    fn new(n: usize) -> Self {
        return Self {
            n: n,
            t: vec![(0usize, 0usize); 4*n],
        };
    }

    fn merge(&self, a: (usize, usize), b: (usize, usize)) -> (usize, usize) {
        let ((l_len, l_cnt), (r_len, r_cnt)) = (a, b);
        match (l_len, r_len) {
            // decide on maximum lengths
            (l, r) if (l < r) => return b,
            (l, r) if (l > r) => return a,
            _                 => return (l_len, l_cnt + r_cnt),
        }
    }

    fn update(&mut self, index: usize, value: (usize, usize)) {
        return self._update(0, 0, self.n - 1, index, value);
    }

    fn _update(
        &mut self,
        node: usize,
        start: usize,
        end: usize,
        index: usize,
        value: (usize, usize),
    ) {
        if start == end {
            let (have_len, _) = self.t[node];
            match (have_len, value.0) {
                (hl, nl) if nl  > hl => { self.t[node]    = value;   return; }
                (hl, nl) if nl == hl => { self.t[node].1 += value.1; return; }
                _                    => { return; }
            }
        } else {
            let mid = start + ((end - start) >> 1);
            if index <= mid {
                self._update(2*node + 1, start, mid, index, value);
            } else {
                self._update(2*node + 2, mid + 1, end, index, value);
            }
            self.t[node] = self.merge(self.t[2*node + 1], self.t[2*node + 2]);
        }
    }

    fn find(&self, left: usize, right: usize) -> (usize, usize) {
        return self._find(0, 0, self.n - 1, left, right);
    }

    fn _find(
        &self,
        node: usize,
        start: usize,
        end: usize,
        left: usize,
        right: usize,
    ) -> (usize, usize) {
        if right < start || end < left {
            return (0usize, 0usize);
        }
        if left <= start && end <= right {
            return self.t[node];
        }
        let mid = start + ((end - start) >> 1);
        return self.merge(
            self._find(2*node + 1, start, mid, left, right),
            self._find(2*node + 2, mid + 1, end, left, right),
        );
    }
}

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn find_number_of_lis(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut arr = nums.clone();
        arr.sort();
        arr.dedup();
        let mut indices = arr
            .into_iter()
            .fold(
                (std::collections::HashMap::<i32, usize>::new(), 1usize),
                |(mut seen, count), num| {
                    *seen.entry(num).or_insert(count);
                    (seen, count + 1)
                },
            )
            .0;
        let m = indices.len() + 1;
        let mut st = SegTree::new(m);

        for left in 0..n {
            let index = *indices.get(&nums[left]).unwrap_or(&0);
            let (prev_len, prev_cnt) = st.find(0, index.saturating_sub(1));
            st.update(
                index,
                (prev_len + 1, if prev_len == 0 { 1usize } else { prev_cnt }),
            );
        }

        return st.find(0, m - 1).1 as i32;
    }
}

fn main() {}
