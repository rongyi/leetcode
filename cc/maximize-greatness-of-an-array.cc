// https://leetcode.com/problems/maximize-greatness-of-an-array/
#include "xxx.hpp"

class Solution {
public:
  int maximizeGreatness(vector<int> &nums) {
    map<int, int> num_cnt;
    for (auto &num : nums) {
      num_cnt[num]++;
    }
    int bigger_left = num_cnt.rbegin()->second;
    // biggest one has no number bigger than it
    int greatness = 0;
    // from the second biggest one
    // we count how many bigger number available
    // so we can put those bigger number to smaller
    // one
    for (auto it = next(num_cnt.rbegin()); it != num_cnt.rend(); ++it) {
      int consume = min(bigger_left, it->second);
      // for smaller one
      bigger_left += it->second;
      bigger_left -= consume;
      greatness += consume;
    }

    return greatness;
  }
};
