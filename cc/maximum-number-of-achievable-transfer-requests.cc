// http://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/description/
#include "xxx.hpp"
class Solution {
public:
  // 出度入度来考虑
  int maximumRequests(int n, vector<vector<int>> &requests) {
    int ret = 0;
    const int reqn = requests.size();
    const int limit = (1 << reqn);
    for (int cur_comb = 1; cur_comb < limit; ++cur_comb) {
      vector<int> outdeg(n, 0);
      vector<int> indeg(n, 0);
      int cur_tour = 0;
      for (int i = 0; i < reqn; ++i) {
        // 当前组合有这个request
        if ((cur_comb & (1 << i)) != 0) {
          cur_tour++;

          outdeg[requests[i][0]]++;
          indeg[requests[i][1]]++;
        }
      }

      // 节点出度以及入度相同
      int num_even = 0;
      // 统计参与的节点数量
      int num_node = 0;
      for (int i = 0; i < n; ++i) {
        if (indeg[i] > 0) {
          num_node++;
        }
        if (indeg[i] > 0 && indeg[i] == outdeg[i]) {
          num_even++;
        }
      }

      // 所有节点都是even节点
      if (num_even == num_node) {
        ret = max(ret, cur_tour);
      }
    }

    return ret;
  }
};
