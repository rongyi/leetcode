// https://leetcode.com/problems/make-sum-divisible-by-p/description/
use crate::Solution;

use std::collections::HashMap;
impl Solution {
    pub fn min_subarray(nums: Vec<i32>, p: i32) -> i32 {
        let n: i32 = nums.len() as i32;
        let need = nums.iter().fold(0, |mut acc, x| {
            acc = (acc + x) % p;
            acc
        });

        let mut prefix_sum: HashMap<i32, i32> = HashMap::new();
        prefix_sum.insert(0, -1);
        let mut cur_sum = 0;
        let mut ret: i32 = n;
        for (i, num) in nums.iter().enumerate() {
            cur_sum = (cur_sum + num) % p;
            prefix_sum.insert(cur_sum, i as i32);
            let expect: i32 = (cur_sum - need + p) % p;
            if prefix_sum.contains_key(&expect) {
                ret = std::cmp::min(ret, i as i32 - prefix_sum.get(&expect).unwrap());
            }
        }
        if ret == n {
            -1
        } else {
            ret
        }
    }
}
