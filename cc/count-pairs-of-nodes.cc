// http://leetcode.com/problems/count-pairs-of-nodes/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> countPairs(int n, vector<vector<int>> &edges,
                         vector<int> &queries) {
    vector<int> sorted_count(n + 1, 0);
    vector<int> count(n + 1, 0);
    // 两个点之间的共同边统计
    vector<unordered_map<int, int>> shared_count(n + 1);
    for (auto &e : edges) {
      ++count[e[0]];
      ++count[e[1]];
      sorted_count[e[0]] = count[e[0]];
      sorted_count[e[1]] = count[e[1]];

      ++shared_count[min(e[0], e[1])][max(e[0], e[1])];
    }
    sort(sorted_count.begin(), sorted_count.end());

    vector<int> ret;
    for (auto q : queries) {
      ret.push_back(0);
      for (int i = 1, j = n; i < j;) {
        // 先统计 degree(a) + degree(b) > q
        if (sorted_count[i] + sorted_count[j] > q) {
          ret.back() += (j - i);
          --j;
        } else {
          ++i;
        }
      }
      for (int i = 1; i <= n; ++i) {
        for (auto [j, sh_cnt] : shared_count[i]) {
          // 再减去degree(a) + degree(b) - edgeof(a, b) <= q
          if (count[i] + count[j] > q && count[i] + count[j] - sh_cnt <= q) {
            --ret.back();
          }
        }
      }
    }

    return ret;
  }
};
