pub(crate) struct Solution;
// mod l1423;
// mod l1424;
// mod l1425;
// mod l1431;
// mod l1436;
// mod l1437;
// mod l1588;
// mod l1589;
// mod l1590;
// mod l1601;
// mod l1603;
// mod l1604;
// mod l1605;

mod l1833 {
    struct Solution;
    impl Solution {
        pub fn max_ice_cream(costs: Vec<i32>, coins: i32) -> i32 {
            let mut c = costs.clone();
            c.sort();
            let mut coins = coins;
            let mut ret = 0;
            for p in c.iter() {
                if *p > coins {
                    break;
                }
                ret += 1;
                coins -= p;
            }

            ret
        }
    }
}

mod l1837 {
    struct Solution;
    impl Solution {
        pub fn sum_base(n: i32, k: i32) -> i32 {
            let mut n = n;
            let mut base = k;
            while base <= n {
                base *= k;
            }
            base /= k;

            let mut ret = 0;
            while n != 0 {
                ret += n / base;
                n %= base;
                base /= k;
            }

            ret
        }
    }
}

mod l1838 {
    impl super::Solution {
        pub fn max_frequency(nums: Vec<i32>, k: i32) -> i32 {
            let mut nums = nums;
            nums.sort();
            let mut ret: i64 = 1;
            let mut sum: i64 = 0;
            let mut i: i64 = 0;
            let mut j: i64 = 0;
            let n: i64 = nums.len() as i64;
            while j < n {
                sum += nums[j as usize] as i64;

                while (j - i + 1) * nums[j as usize] as i64 - sum > (k as i64) {
                    sum -= nums[i as usize] as i64;
                    i += 1;
                }

                ret = std::cmp::max(ret, (j - i + 1) as i64);

                j += 1;
            }

            ret as i32
        }
    }
}

mod lxxx {
    struct Solution;
    impl Solution {
        pub fn replace_digits(s: String) -> String {
            let mut ret: String = String::new();
            for (i, c) in s.chars().enumerate() {
                if c.is_digit(10) {
                    let change =
                        (s.chars().nth(i - 1).unwrap() as u8 + (c as u8 - '0' as u8) as u8) as char;
                    ret.push(change);
                } else {
                    ret.push(c);
                }
            }
            ret
        }
    }
}

mod l1012 {
    struct Solution;
    impl Solution {
        pub fn maximum_rows(matrix: Vec<Vec<i32>>, num_select: i32) -> i32 {
            let n: usize = matrix[0].len();
            let mut ret = 0;
            for mask in 0..(1 << n as u32) {
                if u32::count_ones(mask) > num_select as u32 {
                    continue;
                }
                let mut cur = 0;
                for row in &matrix {
                    let mut j = 0;
                    while j < n {
                        if row[j] == 1 && ((1 << j) & mask) == 0 {
                            break;
                        }
                        j += 1;
                    }
                    cur += if j == n { 1 } else { 0 };
                }
                ret = std::cmp::max::<i32>(ret, cur);
            }

            ret
        }
    }
}
mod l101202 {
    use std::collections::VecDeque;

    struct Solution;
    impl Solution {
        pub fn maximum_robots(charge_times: Vec<i32>, running_costs: Vec<i32>, budget: i64) -> i32 {
            let mut q: VecDeque<i32> = VecDeque::new();
            let mut i = 0;
            let mut j = 0;
            let sz: usize = charge_times.len();
            let mut cost = 0i64;
            while i < sz {
                cost += running_costs[i] as i64;
                while !q.is_empty() && q.back().unwrap() < &charge_times[i] {
                    q.pop_back();
                }
                q.push_back(charge_times[i]);
                if (cost * (i - j + 1) as i64 + (*q.front().unwrap()) as i64) > budget {
                    cost -= running_costs[j] as i64;
                    if q.front().unwrap() == &charge_times[j] {
                        q.pop_front();
                    }

                    j += 1;
                }

                i += 1;
            }

            (sz - j) as i32
        }
    }
}

mod l101203 {
    struct Solution;
    impl Solution {
        pub fn check_distances(s: String, distance: Vec<i32>) -> bool {
            let mut processed: Vec<Option<usize>> = vec![None; 26];
            for (i, c) in s.chars().enumerate() {
                let idx: usize = (c as u8 - b'a') as usize;
                if processed[idx].is_none() {
                    processed[idx] = Some(i);
                } else {
                    let calced = i - processed[idx].unwrap() - 1;
                    if calced as i32 != distance[idx] {
                        return false;
                    }
                }
            }
            true
        }
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
    #[test]
    fn test_freq() {
        let nums: Vec<i32> = vec![3, 9, 6];
        let ret = super::Solution::max_frequency(nums, 2);
        assert_eq!(ret, 1);
    }
}
