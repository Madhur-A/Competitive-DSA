



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

// a better (and shorter) approach would be to use
// ordered tree map, viz., BTreeMap.

impl Solution {
    #[allow(unused)]
    pub fn odd_even_jumps(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut next_ge = nums.iter().enumerate().map(|(i, &num)| (i, num)).collect::<Vec<(usize, i32)>>();
        next_ge.sort_by(|a, b| if a.1 == b.1 { a.0.cmp(&b.0) } else { a.1.cmp(&b.1) });
        let next_ge = next_ge.into_iter().map(|a| a.0).collect::<Vec<usize>>();

        let mut next_le = nums.iter().enumerate().map(|(i, &num)| (i, num)).collect::<Vec<(usize, i32)>>();
        next_le.sort_by(|a, b| if b.1 == a.1 { a.0.cmp(&b.0) } else { b.1.cmp(&a.1) });
        let next_le = next_le.into_iter().map(|a| a.0).collect::<Vec<usize>>();

        let mut indices_ge = vec![-1i32; n];
        let mut indices_le = vec![-1i32; n];

        let mut stack = Vec::<usize>::new();

        for &i in next_ge.iter() {
            while let Some(&top) = stack.last() {
                if top < i {
                    indices_ge[top] = i as i32;
                    stack.pop();
                } else { break; }
            }
            stack.push(i);
        }

        stack.clear();

        for &i in next_le.iter() {
            while let Some(&top) = stack.last() {
                if top < i {
                    indices_le[top] = i as i32;
                    stack.pop();
                } else { break; }
            }
            stack.push(i);
        }

        let mut ge = vec![false; n];
        let mut le = vec![false; n];

        ge[n - 1] = true;
        le[n - 1] = true;

        let last = n - 1;

        for i in (0..last).rev() {
            if indices_ge[i] != -1 {
                ge[i] = le[indices_ge[i] as usize];
            }
            if indices_le[i] != -1 {
                le[i] = ge[indices_le[i] as usize];
            }
        }

        return ge.iter().filter(|&&valid| valid == true).count() as i32;
    }
}

fn main() {
    println!("res: {}", Solution::odd_even_jumps(vec![5,1,3,4,2]));
    println!(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
}
