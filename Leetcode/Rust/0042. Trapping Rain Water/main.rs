



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let mut t = Vec::<usize>::new();
        let mut res = 0i32;
        for i in 0..height.len() {
            while !t.is_empty() && height[i] > height[*t.last().unwrap_or(&0)] {
                let mid = t.pop().unwrap_or(0);
                if t.is_empty() { break; }
                let second_last = *t.last().unwrap_or(&0);
                let  width = (i - second_last - 1) as i32;
                let length = std::cmp::min(height[second_last], height[i]) - height[mid];
                res += width * length;
            }
            t.push(i);
        }


        return res;
    }
}

fn main() {}
