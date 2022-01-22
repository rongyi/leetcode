// http://leetcode.com/problems/gas-station/description/
#include "xxx.hpp"

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int start = -1;
    int sum = 0;
    int cur = 0;
    for (int i = 0; i < gas.size(); i++) {
      cur += gas[i] - cost[i];

      // 不管从哪里开始兜一圈的油耗总和不变，
      sum += gas[i] - cost[i];
      // 表示从前面某个点开始到当前节点“够不着”
      if (cur < 0) {
        start = i;
        cur = 0;
      }
    }
    return sum >= 0 ? start + 1 : -1;
  }
};
