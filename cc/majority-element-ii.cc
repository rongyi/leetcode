// http://leetcode.com/problems/majority-element-ii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    int sz = nums.size();
    int cnt = sz / 3;
    sort(nums.begin(), nums.end());
    vector<int> ret;
    // make code more shorter
    for (auto it = nums.begin(); it != nums.end();) {
      auto up = upper_bound(nums.begin(), nums.end(), *it);
      auto d = distance(it, up);
      if (d > cnt) {
        ret.push_back(*it);
      }
      it = up;
    }

    return ret;
  }
};
