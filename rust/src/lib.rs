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

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
