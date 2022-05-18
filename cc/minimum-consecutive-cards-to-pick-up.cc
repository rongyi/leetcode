// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/
#include "xxx.hpp"

class Solution {
public:
  int minimumCardPickup(vector<int> &cards) {
    map<int, vector<int>> group;
    int sz = cards.size();
    for (int i = 0; i < sz; ++i) {
      group[cards[i]].push_back(i);
    }
    int ret = numeric_limits<int>::max();
    for (auto &kv : group) {
      for (int i = 0; i < kv.second.size() - 1; ++i) {
        int cur_diff = kv.second[i + 1] - kv.second[i] + 1;
        ret = min(ret, cur_diff);
      }
    }

    if (ret == numeric_limits<int>::max()) {
      return -1;
    }

    return ret;
  }
};
