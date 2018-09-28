// http://leetcode.com/problems/n-queens/description/
#include "one.h"

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ret;
    columns_ = vector<int>(n, 0);
    vector<int> queen_col_vec(n, 0);

    dfs(ret, queen_col_vec, 0, n);

    return ret;
  }

private:
  void dfs(vector<vector<string>> &ret, vector<int> &queen_col_vec, int row,
           const int n) {
    // 这里其实隐含一个意思，走到这里的都是OK的，因为最后一次还能继续递归进来说明连最后一个
    // 也是合法的位置
    if (row == n) {
      vector<string> newlayout;
      for (int i = 0; i < n; ++i) {
        string cur_row(n, '.');
        cur_row[queen_col_vec[i]] = 'Q';
        newlayout.push_back(cur_row);
      }
      ret.push_back(newlayout);
      return;
    }
    for (int j = 0; j < n; ++j) {
      bool ok = (columns_[j] == 0) &&
                (main_diag_.find(row + j) == main_diag_.end()) &&
                (anti_diag_.find(row - j) == anti_diag_.end());
      if (!ok) {
        continue;
      }
      // 当前行可以放在j列这个位置
      queen_col_vec[row] = j;

      // 当前列标记
      columns_[j] = 1;
      // 主辅对角线更新
      main_diag_.insert(row + j);
      anti_diag_.insert(row - j);
      dfs(ret, queen_col_vec, row + 1, n);

      // restore
      columns_[j] = 0;
      main_diag_.erase(row + j);
      anti_diag_.erase(row - j);
      // 这里为什么没有回退 queen_col_vec?
      // 因为实际上不需要，每一轮都是重新写，如果直到最后一个也合法，就进最前面的 n条件匹配。
      // 脏的也就走过去了，不会被记录，总体上走到 插入结果的判断中每一个 queen_col_vec 都被重置了
    }
  }

private:
  // 标记哪一列上放置了皇后
  vector<int> columns_;
  // 标记占据哪些主对角线
  // 在一个正斜线上有一个特征: row + col == 固定值
  std::unordered_set<int> main_diag_;
  // 标记占据哪些辅对角线
  // 同样在一个反斜线上有一个特征： row - col == 固定值
  std::unordered_set<int> anti_diag_;
};

int main() {
  Solution so;
  auto ret = so.solveNQueens(4);
  cout << ret.size() << endl;
  for (auto v : ret) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
}
