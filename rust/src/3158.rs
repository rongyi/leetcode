use std::vec;

struct Solution;

impl Solution {
    pub fn duplicate_number_xor(mut nums: Vec<i32>) -> i32 {
        let mut dups = vec![];
        nums.sort();

        for (i, &num) in nums.iter().enumerate().skip(1) {
            if num == nums[i - 1] && (dups.is_empty() || *dups.last().unwrap() != num) {
                dups.push(num);
            }
        }

        dups.iter().fold(0, |acc, &cur| acc ^ cur)
    }
}

fn main() {
    println!("todo");
}
