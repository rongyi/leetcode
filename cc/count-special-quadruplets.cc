// https://leetcode.com/problems/count-special-quadruplets/
#include "xxx.hpp"

class Solution {
public:
  int countQuadruplets(vector<int> &nums) {
    int sz = nums.size();
    set<vector<int>> uniq;
    for (int i = 0; i < sz; ++i) {
      for (int j = i + 1; j < sz; ++j) {
        for (int k = j + 1; k < sz; ++k) {
          for (int l = k + 1; l < sz; ++l) {
            if (nums[i] + nums[j] + nums[k] == nums[l]) {
              uniq.insert({i, j, k, l});
            }
          }
        }
      }
    }

    return uniq.size();
  }
};
