// http://leetcode.com/problems/subsets/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ret;
    int sz = nums.size();
    for (int b = 0; b < (1 << sz); b++) {
      vector<int> cur;
      for (int i = 0; i < sz; i++) {
        if ((b >> i) & 0x1) {
          cur.push_back(nums[i]);
        }
      }
      ret.push_back(cur);
    }

    return ret;
  }
};
