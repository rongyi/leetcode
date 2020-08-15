// http://leetcode.com/problems/brick-wall/description/
#include "xxx.h"

class Solution {
public:
  int leastBricks(vector<vector<int>> &wall) {
    // not INT_MIN
    int ret = 0;
    unordered_map<int, int> sum_count;
    for (auto &layer : wall) {
      const int n = layer.size();
      vector<int> sum(n + 1, 0);
      // 忽略最后一个，因为最后一个加起来的sum都是一样的
      // 题目要求忽略左边和右边的两条垂线
      for (int i = 0; i < n - 1; i++) {
        sum[i + 1] = sum[i] + layer[i];
        sum_count[sum[i + 1]]++;
        ret = max(ret, sum_count[sum[i + 1]]);
      }
    }

    return wall.size() - ret;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2},
                            {2, 4},       {3, 1, 2}, {1, 3, 1, 1}};
  auto ret = so.leastBricks(input);
  cout << ret << endl;
}
