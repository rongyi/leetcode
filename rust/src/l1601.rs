use crate::Solution;

impl Solution {
    pub fn maximum_requests(n: i32, requests: Vec<Vec<i32>>) -> i32 {
        let m = requests.len();
        let total_comb = 1 << m;
        let mut ret: i32 = 0;
        let mut cur_comb = 1;
        while cur_comb < total_comb {
            let mut outdeg: Vec<i32> = vec![0; n as usize];
            let mut indeg: Vec<i32> = vec![0; n as usize];
            let mut cur_tour: i32 = 0;

            let mut i = 0;
            while i < m {
                if ((cur_comb) & (1 << i)) != 0 {
                    cur_tour += 1;
                    outdeg[requests[i][0] as usize] += 1;
                    indeg[requests[i][1] as usize] += 1;
                }
                i += 1;
            }
            let mut num_even = 0;
            let mut num_node = 0;
            for (od, id) in outdeg.iter().zip(indeg.iter()) {
                if id > &0 {
                    num_node += 1;
                }
                if id > &0 && od == id {
                    num_even += 1;
                }
            }
            if num_even == num_node {
                ret = std::cmp::max(ret, cur_tour);
            }

            cur_comb += 1;
        }

        ret
    }
}
