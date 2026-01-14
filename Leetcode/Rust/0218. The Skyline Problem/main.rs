



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn merge(left: Vec<Vec<i32>>, right: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (mut h1, mut h2, mut i, mut j) = (0, 0, 0, 0);
        let mut res = vec![];

        while i < left.len() && j < right.len() {
            match (left[i][0], right[j][0]) {
                (l, r) if l < r => {
                    let (x, max_h) = (left[i][0], std::cmp::max(h2, left[i][1]));
                    if res.last().map_or(true, |r: &Vec<i32>| r[1] != max_h) {
                        res.push(vec![x, max_h]);
                    }
                    (h1, i) = (left[i][1], i + 1);
                },
                (l, r) if l > r => {
                    let (x, max_h) = (right[j][0], std::cmp::max(h1, right[j][1]));
                    if res.last().map_or(true, |r: &Vec<i32>| r[1] != max_h) {
                        res.push(vec![x, max_h]);
                    }
                    (h2, j) = (right[j][1], j + 1);
                },
                _              => {
                    let (x, max_h) = (left[i][0], std::cmp::max(left[i][1], right[j][1]));
                    if res.last().map_or(true, |r: &Vec<i32>| r[1] != max_h) {
                        res.push(vec![x, max_h]);
                    }
                    (h1, h2, i, j) = (left[i][1], right[j][1], i + 1, j + 1);
                }
            }
        }

        while i < left.len()  { res.push(left[i].clone());  i += 1; }
        while j < right.len() { res.push(right[j].clone()); j += 1; }


       return res;
    }

    pub fn build(buildings: &[Vec<i32>], left: usize, right: usize) -> Vec<Vec<i32>> {
        if left == right {
            let b = &buildings[left];
            return vec![vec![b[0], b[2]], vec![b[1], 0]];
        }

        let mid = left + ((right - left) >> 1);
        let l_skyline = Self::build(buildings, left, mid);
        let r_skyline = Self::build(buildings, mid + 1, right);

        return Self::merge(l_skyline, r_skyline)
    }

    #[allow(unused)]
    pub fn get_skyline(buildings: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = buildings.len();
        if n == 0 { return vec![]; }

        return Self::build(&buildings, 0, n - 1)
    }
}

fn main() {}
