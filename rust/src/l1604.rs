// http://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/description/
use crate::Solution;

use std::collections::BTreeMap;

impl Solution {
    pub fn alert_names(key_name: Vec<String>, key_time: Vec<String>) -> Vec<String> {
        let mut count: BTreeMap<String, Vec<i32>> = BTreeMap::new();

        for (name, stamp) in key_name.iter().zip(key_time.iter()) {
            let t = Solution::time_to_int(&stamp);
            count.entry(name.clone()).or_insert(Vec::new()).push(t);
        }

        let mut ret: Vec<String> = Vec::new();

        for (k, v) in count.iter_mut() {
            if !Solution::check(v) {
                ret.push(k.clone());
            }
        }

        ret
    }

    fn check(ts: &mut [i32]) -> bool {
        ts.sort();
        let mut start_index: usize = 0;
        for (i, curts) in ts.iter().enumerate() {
            if curts - ts[start_index] <= 60 {
                if i - start_index + 1 >= 3 {
                    return false;
                }
            } else {
                start_index += 1;
            }
        }
        true
    }

    fn time_to_int(s: &str) -> i32 {
        let comma = s.find(':').unwrap();
        let h = &s[..comma];
        let m = &s[comma + 1..];

        h.parse::<i32>().unwrap() * 60 + m.parse::<i32>().unwrap()
    }
}
