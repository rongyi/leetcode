// https://leetcode.com/problems/destination-city/
use crate::Solution;
use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn dest_city(paths: Vec<Vec<String>>) -> String {
        let mut count: HashMap<String, Vec<String>> = HashMap::new();
        let mut cits: HashSet<String> = HashSet::new();

        let ret: String = "".to_string();

        for p in paths.iter() {
            let c0 = p[0].clone();
            let c1 = p[1].clone();

            count
                .entry(p[0].clone())
                .or_insert(Vec::new())
                .push(p[1].clone());
            cits.insert(c0);
            cits.insert(c1);
        }

        for c in cits.iter() {
            if !count.contains_key(c) {
                return c.clone();
            }
        }
        return ret;
    }
}
