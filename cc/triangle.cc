// http://leetcode.com/problems/triangle/description/
#include "xxx.hpp"

class Solution {
public:
  // 超时，可以帮助理解一下
  int minimumTotalTLEVersion(vector<vector<int>> &triangle) {
    if (triangle.empty()) {
      return 0;
    }
    int ret = numeric_limits<int>::max();
    dfs(triangle, 0, 0, 0, ret);
    return ret;
  }
  int minimumTotal(vector<vector<int>> &triangle) {
    if (triangle.empty()) {
      return 0;
    }
    const int m = triangle.size();
    vector<vector<int>> dp(m, vector<int>(m, 0));

    if (m == 1) {
      return triangle[0][0];
    }
    dp[0][0] = triangle[0][0];
    // reduce by level
    //     0
    //   1   2
    // 3   4    5
    // 注意看一下，走到3只能是从1过来，走到5只能是从2过来，走到4可能是1，也可能是2过来，
    // 然后算一下上一层index和当前这个index关系即可
    for (int i = 1; i < m; ++i) {
      const auto cur_vec = triangle[i];
      for (int j = 0; j < cur_vec.size(); ++j) {
        if (j == 0) {
          dp[i][j] = dp[i - 1][j] + cur_vec[j];
        } else if (j == cur_vec.size() - 1) {
          dp[i][j] = dp[i - 1][j - 1] + cur_vec[j];
        } else {
          dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + cur_vec[j];
        }
      }
    }
    return *min_element(dp[m - 1].begin(), dp[m - 1].end());
  }

private:
  void dfs(vector<vector<int>> &triangle, int cur_level, int cur_indx,
           int cur_sum, int &ret) {
    if (cur_level == triangle.size()) {
      // cout << cur_sum << "here" <<endl;
      ret = min(ret, cur_sum);
      return;
    }
    const int cur_range = triangle[cur_level].size();
    // not a valid range
    if (cur_indx < 0 || cur_indx >= cur_range) {
      return;
    }
    // three step
    dfs(triangle, cur_level + 1, cur_indx,
        cur_sum + triangle[cur_level][cur_indx], ret);
    dfs(triangle, cur_level + 1, cur_indx + 1,
        cur_sum + triangle[cur_level][cur_indx], ret);
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{-1}, {3, 2}, {-3, 1, -1}};
  auto ret = so.minimumTotal(input);
  cout << ret << endl;
}
