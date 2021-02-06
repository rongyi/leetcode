// https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/description/
use crate::Solution;

impl Solution {
    pub fn max_sum_range_query(nums: Vec<i32>, requests: Vec<Vec<i32>>) -> i32 {
        let m: i64 = 1e9 as i64 + 7;
        let mut count: Vec<i32> = vec![0; nums.len()];
        for pair in &requests {
            count[pair[0] as usize] += 1;
            if pair[1] + 1 < count.len() as i32 {
                count[pair[1] as usize + 1] -= 1;
            }
        }
        let mut i = 1;
        while i < count.len() {
            count[i] += count[i - 1];
            i += 1;
        }
        count.sort();
        let mut nums = nums.clone();
        nums.sort();
        let mut ret: i64 = 0;
        let mut i = 0;
        while i < nums.len() {
            ret = (ret + (nums[i] as i64 * count[i] as i64)) % m;
            i += 1;
        }
        ret as i32
    }
}
