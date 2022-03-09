// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/
#include "xxx.hpp"

class Solution {
public:
  int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime) {
    int sz = plantTime.size();
    vector<pair<int, int>> v;
    for (int i= 0; i < sz; ++i) {
      v.push_back({growTime[i], plantTime[i]});
    }
    sort(v.begin(), v.end());
    int ret = 0;
    for (auto [g, p] : v) {
      ret = max(ret, g) + p;
    }

    return ret;
  }
};
