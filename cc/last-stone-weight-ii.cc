// http://leetcode.com/problems/last-stone-weight-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {

    // We add/subtract each stone to/from all possible sums achievable after
    // processing previous stones. In the end, we return the smallest absolute
    // value.

    // To track possible sums, we need to use hash set to avoid duplicates (and
    // TLE). We could also use a byte array, but the code seemed a bit more
    // complicated to me.
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
