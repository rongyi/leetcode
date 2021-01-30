#[allow(dead_code)]
use std::collections::HashMap;
use std::collections::HashSet;
use std::collections::VecDeque;

// placebo
pub struct Solution;

impl Solution {
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

        return true;
    }

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

    #[allow(dead_code)]
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

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let input: Vec<i32> = vec![1, 4, 2, 5, 3];
        let ret = Solution::sum_odd_length_subarrays(input);
        assert_eq!(ret, 58);
    }
}
