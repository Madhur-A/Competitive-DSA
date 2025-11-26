//-author("Miho Nishizumi"). % "Ooarai Joshigakuin Shōri!"



#[allow(unused_imports)]
use itertools::Itertools;

#[allow(unused)]
struct Solution;

impl Solution {
    const MOD: i32 = 1_000_000_007;

    pub fn num_sub(s: String) -> i32 {
        s.chars().fold((0, 0), |(res, curr), current_char|{
            match current_char {
                '1' => ((res + curr + 1) % Self::MOD, curr + 1),
                 _  => ( res, 0 ),
            }
        }).0
    }
}

fn main() {}
