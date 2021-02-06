// https://leetcode.com/problems/constrained-subsequence-sum/description/
use crate::Solution;
use std::collections::VecDeque;

impl Solution {
    pub fn constrained_subset_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mut dp: Vec<i32> = vec![0; nums.len()];
        let mut q: VecDeque<i32> = VecDeque::new();

        let mut ret = std::i32::MIN;

        for i in 0..nums.len() {
            let mut tmp = 0;
            if !q.is_empty() {
                let idx: i32 = *q.front().unwrap();
                tmp = dp[idx as usize];
            }
            let cur_max = std::cmp::max(0, tmp);
            dp[i] = nums[i] + cur_max;
            ret = std::cmp::max(ret, dp[i]);

            while !q.is_empty() && dp[i] >= dp[*q.back().unwrap() as usize] {
                q.pop_back();
            }
            q.push_back(i as i32);
            if i - *q.front().unwrap() as usize + 1 > k as usize {
                q.pop_front();
            }
        }

        ret
    }
}
