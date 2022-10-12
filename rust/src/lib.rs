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
