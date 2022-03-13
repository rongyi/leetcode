// https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
#include "xxx.hpp"

class Solution {
public:
  int countElementsNotVeryGood(vector<int> &nums) {
    set<int> uniq(nums.begin(), nums.end());
    int ret = 0;

    for (auto num : nums) {
      auto it = uniq.find(num);
      if (it != uniq.begin() && it != prev(uniq.end())) {
        ret++;
      }
    }

    return ret;
  }
  int countElements(vector<int> &nums) {
    int right = *max_element(begin(nums), end(nums));
    int left = *min_element(begin(nums), end(nums));
    int ret = 0;
    for (auto &num: nums) {
      if (num < right && num > left) {
        ++ret;
      }
    }
    return ret;
  }
};
