// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/description/
use crate::Solution;

impl Solution {
    pub fn sum_odd_length_subarrays(arr: Vec<i32>) -> i32 {
        let mut psum: Vec<i32> = vec![0; arr.len() + 1];
        for (i, num) in arr.iter().enumerate() {
            psum[i + 1] = num + psum[i];
        }
        let mut i: usize = 0;
        let mut ret: i32 = 0;
        while i < arr.len() {
            let mut j: usize = i;
            while j < arr.len() {
                if (j - i + 1) % 2 == 1 {
                    ret += psum[j + 1] - psum[i];
                }
                j += 1;
            }
            i += 1;
        }

        return ret;
    }
}
