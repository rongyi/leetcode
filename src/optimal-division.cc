// http://leetcode.com/problems/optimal-division/description/
#include "xxx.h"

class Solution {
public:
  string optimalDivision(vector<int> &nums) {
    stringstream ss;
    if (nums.empty()) {
      return "";
    }
    ss << nums[0];
    if (nums.size() == 1) {
      return ss.str();
    }
    if (nums.size() == 2) {
      ss << "/" << nums[1];
      return ss.str();
    }
    ss << "/(" << nums[1];
    for (int i = 2; i < nums.size(); i++) {
      ss << "/" << nums[i];
    }
    ss << ")";
    return ss.str();
  }
};
