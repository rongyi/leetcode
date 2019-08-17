// http://leetcode.com/problems/last-stone-weight-ii/description/
#include "xxx.h"

class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    unordered_set<int> s1{0};
    for (auto cur_stone : stones) {
      unordered_set<int> s2{};
      for (auto cur_sum : s1) {
        s2.insert(cur_sum - cur_stone);
        s2.insert(cur_sum + cur_stone);
      }
      swap(s1, s2);
    }
    return abs(*min_element(s1.begin(), s1.end(),
                            [](int i, int j) { return abs(i) < abs(j); }));
  }
};
