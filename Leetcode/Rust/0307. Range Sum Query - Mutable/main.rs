



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct NumArray {
    nums: Vec<i32>,
    t: Vec<i32>,
    n: usize,
}

impl NumArray {
    #[allow(unused)]
    fn new(nums: Vec<i32>) -> Self {
        let _n = nums.len();
        let mut instance = Self {
            nums: nums.clone(),
            t: vec![0i32; 4*_n],
            n: _n,
        };
        instance.build(0, 0, nums.len() - 1);
        return instance;
    }

    fn build(&mut self, node: usize, start: usize, end: usize) {
        if start == end {
            self.t[node] = self.nums[start];
        } else {
            let mid = start + ((end - start) >> 1);
            self.build(2*node + 1, start, mid);
            self.build(2*node + 2, mid + 1, end);
            self.t[node] = self.t[2*node + 1] + self.t[2*node + 2];
        }
    }

    fn _update(&mut self, node: usize, start: usize, end: usize, index: usize, val: i32) {
        if start == end {
            self.t[node] = val;
            return;
        }
        let mid = start + ((end - start) >> 1);
        if index <= mid {
            self._update(2*node + 1, start, mid, index, val);
        } else {
            self._update(2*node + 2, mid + 1, end, index, val);
        }
        self.t[node] = self.t[2*node + 1] + self.t[2*node + 2];
    }

    #[allow(unused)]
    fn update(&mut self, index: i32, val: i32) {
        return self._update(0, 0, self.n - 1, index as usize, val);
    }

    fn _sum_range(&self, node: usize, start: usize, end: usize, left: usize, right: usize) -> i32 {
        if start > right || end < left {
            return 0i32;
        }
        if left <= start && end <= right {
            return self.t[node];
        }
        let mid = start + ((end - start) >> 1);
        return
            self._sum_range(2*node + 1, start, mid, left, right) +
            self._sum_range(2*node + 2, mid + 1, end, left, right);
    }

    #[allow(unused)]
    fn sum_range(&self, left: i32, right: i32) -> i32 {
        return self._sum_range(0, 0, self.n - 1, left as usize, right as usize);
    }
}

fn main() {}
