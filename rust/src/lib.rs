use std::collections::HashMap;
use std::collections::HashSet;

#[allow(dead_code)]
pub fn max_score(card_points: Vec<i32>, k: i32) -> i32 {
    if k == card_points.len() as i32 {
        return card_points.iter().sum();
    }
    let mut cur: i32 = 0;

    for i in 0..k {
        cur += card_points[i as usize];
    }
    let mut ret = cur;

    let mut i = k - 1;
    let mut j = card_points.len() as i32 - 1;
    while i >= 0 && j >= 0 {
        cur = cur - card_points[i as usize] + card_points[j as usize];
        ret = std::cmp::max(ret, cur);

        i -= 1;
        j -= 1;
    }

    ret
}

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

use std::collections::VecDeque;
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

pub fn dest_city(paths: Vec<Vec<String>>) -> String {
    let mut count: HashMap<String, Vec<String>> = HashMap::new();
    let mut cits: HashSet<String> = HashSet::new();

    let ret: String = "".to_string();

    for p in paths.iter() {
        let c0 = p[0].clone();
        let c1 = p[1].clone();

        count.entry(p[0].clone()).or_insert(Vec::new()).push(p[1].clone());
        cits.insert(c0);
        cits.insert(c1);
    }

    for c in cits.iter() {
        if !count.contains_key(c) {
            return c.clone();
        }
    }
    return "".to_string();
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
