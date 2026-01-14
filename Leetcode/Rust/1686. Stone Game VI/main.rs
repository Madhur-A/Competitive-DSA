



#[allow(unused_imports)]
// use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    #[allow(unused)]
    pub fn stone_game_vi(alice: Vec<i32>, betty: Vec<i32>) -> i32 {
        let mut combined = alice.iter().zip(betty.iter()).map(|(&a, &b)| (a, b)).collect::<Vec<(i32, i32)>>();
        combined.sort_by(|a, b| { (b.0 + b.1).cmp(&(a.0 + a.1)) });
        let (a, b) = combined.iter().enumerate().fold((0i32, 0i32), |(a, b), (i, &val)| {
            match i.rem_euclid(2) {
                0 => (a + val.0, b),
                _ => (a, b + val.1)
            }
        });
        return
            match (a, b) {
                (a, b) if a == b =>  0,
                (a, b) if a  > b =>  1,
                _                => -1,
            };
    }
}

fn main() {
    println!(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> compiled successfully!")
}
