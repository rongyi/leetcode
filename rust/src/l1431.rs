// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/
use crate::Solution;

impl Solution {
    pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
        let mut ret: Vec<bool> = Vec::new();
        let mut max_candi: i32 = 0;
        for c in candies.iter() {
            max_candi = std::cmp::max(max_candi, *c);
        }
        for c in candies.iter() {
            if *c + extra_candies >= max_candi {
                ret.push(true);
            } else {
                ret.push(false);
            }
        }

        ret
    }
}
