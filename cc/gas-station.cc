// http://leetcode.com/problems/gas-station/description/
#include "xxx.hpp"

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int sz = gas.size();
    int total_tank = 0;
    int start = 0;
    int cur_tank = 0;

    for (int i = 0; i < sz; i++) {
      total_tank += gas[i] - cost[i];

      cur_tank += gas[i] - cost[i];

      if (cur_tank < 0) {
        cur_tank = 0;
        start = i + 1;
      }
    }
    return total_tank >= 0 ? start : -1;
  }
};
