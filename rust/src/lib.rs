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

use std::collections::HashMap;
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

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
