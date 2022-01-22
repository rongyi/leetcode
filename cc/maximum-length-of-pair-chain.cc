// http://leetcode.com/problems/maximum-length-of-pair-chain/description/
#include "xxx.hpp"

class Solution {
public:
  int findLongestChain(vector<vector<int>> &ps) {
    sort(ps.begin(), ps.end(), [](vector<int> &a, vector<int> &b) -> bool {
      if (a[1] == b[1]) {
        return a[0] < b[0];
      }
      return a[1] < b[1];
    });
    vector<int> &cur = ps[0];

    int ret = 0;
    for (int i = 0; i < ps.size(); i++) {
      // e.g. [1, 2] [3, 4]
      // 保证当前节点的第一个大于cur的最后一个
      if (i == 0 || ps[i][0] > cur[1]) {
        cur = ps[i];
        ret++;
      }
    }
    return ret;
  }
};
