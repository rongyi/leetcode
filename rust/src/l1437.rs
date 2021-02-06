// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/
use crate::Solution;

impl Solution {
    pub fn k_length_apart(nums: Vec<i32>, k: i32) -> bool {
        let mut prev_one_index: i32 = -1;
        for i in 0..nums.len() as i32 {
            if nums[i as usize] == 0 {
                continue;
            }
            if prev_one_index == -1 {
                prev_one_index = i;
            } else {
                if i - prev_one_index - 1 < k {
                    return false;
                }
                prev_one_index = i;
            }
        }

        true
    }
}
