



#[allow(unused_imports)]
// use itertools::Itertools;

/**
 * faster and shorter methods exist, but i wanted to present this one, which uses a segment tree,
 * because it does something i've found interesting. it maps each unique number (in sorted order)
 * to a dense ordinal domain of natural numbers, and builds a prefix-sum structure over that domain.
 * all tree-partitioning decisions are guided solely by these ordinals, while comparisons on the original
 * values are encoded implicitly by the order-preserving mapping (this is done via superimposing the results
 * from subdivisions, as opposed to the binary hopping used by Fenwick trees). this renders the original
 * sequence of numbers merely as pivots, as it operates on the underlying order of the numbers rather than
 * the numbers themselves, which inherently increases the range of applicability of this method.
**/

#[allow(unused)]
struct SegTree {
    n: usize,
    t: Vec<i32>,
}

impl SegTree {
    #[allow(unused)]
    fn new(n: usize) -> Self {
        return Self {
            n: n,
            t: vec![0i32; 4*n],
        };
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
    pub fn count_smaller(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut arr = nums.clone();
        arr.sort();
        arr.dedup();
        let mut indices = arr
            .into_iter()
            .fold(
                (std::collections::HashMap::<i32, i32>::new(), 1i32),
                |(mut g, count), num| {
                    *g.entry(num).or_insert(count);
                    (g, count + 1)
                },
            )
            .0;

        let m = indices.len() + 1;
        let mut st = SegTree::new(m);

        let mut res = vec![0i32; n];
        for left in (0..n).rev() {
            let index = *indices.get(&nums[left]).unwrap_or(&0) as usize;
            res[left] = st.find(0, index.saturating_sub(1));
            st.update(index, 1);
        }

        return res;
    }
}

fn main() {}
