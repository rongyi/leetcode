// http://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/
impl Solution {
    pub fn restore_matrix(row_sum: Vec<i32>, col_sum: Vec<i32>) -> Vec<Vec<i32>> {
        let mut row_sum = row_sum.clone();
        let mut col_sum = col_sum.clone();
        let mut ret: Vec<Vec<i32>> = vec![vec![0; col_sum.len()]; row_sum.len()];

        for i in 0..row_sum.len() {
            for j in 0..col_sum.len() {
                ret[i][j] = std::cmp::min(row_sum[i], col_sum[j]);
                row_sum[i] -= ret[i][j];
                col_sum[j] -= ret[i][j];
            }
        }

        ret
    }
}
