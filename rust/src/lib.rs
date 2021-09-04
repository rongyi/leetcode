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

pub(crate) struct Solution;
#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
