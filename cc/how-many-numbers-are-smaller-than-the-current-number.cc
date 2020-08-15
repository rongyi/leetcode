// http://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/
#include "xxx.h"

class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    vector<int> cp = nums;
    sort(cp.begin(), cp.end());
    unordered_map<int, int> count;
    count[cp[0]] = 0;
    for (int i = 1; i < cp.size(); i++) {
      if (cp[i] != cp[i - 1]) {
        count[cp[i]] = i;
      }
    }
    vector<int> ret;
    for (auto num : nums) {
      ret.push_back(count[num]);
    }

    return ret;
  }
};
