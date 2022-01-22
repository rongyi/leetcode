// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
#include "xxx.hpp"

class Solution {
public:
  int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
    int sz = dist.size();
    int shoot_at = 0;
    multiset<double> s;
    for (int i = 0; i < sz; ++i) {
      s.insert(dist[i] * 1.0 / speed[i]);
    }
    int ret = 0;
    for (auto &monster : s) {
      // shoot at time should be earlier than the monster arrival time
      if (shoot_at >= monster) {
        break;
      }
      ret++;
      shoot_at++;
    }
    return ret;
  }
};
