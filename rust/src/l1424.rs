// https://leetcode.com/problems/diagonal-traverse-ii/description/
use crate::Solution;
use std::collections::HashMap;

impl Solution {
    pub fn find_diagonal_order(nums: Vec<Vec<i32>>) -> Vec<i32> {
        let mut max_sum: i32 = 0;
        let mut group: HashMap<i32, Vec<i32>> = HashMap::new();

        let mut i: i32 = nums.len() as i32 - 1;
        while i >= 0 {
            for j in 0..nums[i as usize].len() as i32 {
                group
                    .entry(i + j)
                    .or_insert(Vec::new())
                    .push(nums[i as usize][j as usize]);
                max_sum = std::cmp::max(max_sum, i + j);
            }
            i -= 1;
        }

        let mut ret: Vec<i32> = Vec::new();
        for i in 0..=max_sum {
            for v in &group[&i] {
                ret.push(*v);
            }
        }

        ret
    }
}
