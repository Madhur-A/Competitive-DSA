



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

// using btree

impl Solution {
    #[allow(unused)]
    pub fn odd_even_jumps(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let last = n - 1;

        let mut ge = vec![false; n];
        let mut le = vec![false; n];

        ge[n - 1] = true;
        le[n - 1] = true;

        let mut seen = std::collections::BTreeMap::<i32, usize>::new();
        seen.insert(nums[last], last);

        for i in (0..last).rev() {
            let num = nums[i];
            if let Some((_, &next_index)) = seen.range(num..).next() {
                ge[i] = le[next_index];
            }
            if let Some((_, &next_index)) = seen.range(..=num).next_back() {
                le[i] = ge[next_index];
            }

            seen.insert(num, i);
        }

        return ge.iter().filter(|&&valid| valid == true).count() as i32;
    }
}

fn main() {
    println!("res: {}", Solution::odd_even_jumps(vec![5,1,3,4,2]));
    println!(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
}
