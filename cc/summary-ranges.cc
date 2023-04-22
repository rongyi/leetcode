// http://leetcode.com/problems/summary-ranges/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    int sz = nums.size();
    if (sz == 0) {
      return {};
    }
    int start = nums[0];
    vector<string> ret;
    for (int i = 1, l = 1; i < sz; i++) {
      // there's a gap
      if (nums[i] != nums[i - 1] + 1) {
        // single case
        if (l == 1) {
          ret.push_back(to_string(start));
        } else {
          ret.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
        }
        start = nums[i];
        l = 1;
      } else {
        l++;
      }
    }
    // the last case
    if (start == nums[sz - 1]) {
      ret.push_back(to_string(start));
    } else {
      ret.push_back(to_string(start) + "->" + to_string(nums[sz - 1]));
    }

    return ret;
  }
};
