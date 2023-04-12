// http://leetcode.com/problems/majority-element/description/
#include "xxx.hpp"

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int sz = nums.size();
    int candidate = nums[0];
    int cnt = 1;
    for (int i = 1; i < sz; i++) {
      if (nums[i] == candidate) {
        cnt++;
      } else {
        cnt--;
      }
      if (cnt == 0) {
        candidate = nums[i];
        cnt = 1;
      }
    }
    return candidate;
  }
};
