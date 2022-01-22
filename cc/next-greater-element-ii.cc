// http://leetcode.com/problems/next-greater-element-ii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    vector<int> ret(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
      ret[i] = nextBigger(nums, i);
    }

    return ret;
  }

private:
  int nextBigger(vector<int> &nums, int pos) {
    // to the end
    for (int i = pos + 1; i < nums.size(); ++i) {
      if (nums[i] > nums[pos]) {
        return nums[i];
      }
    }
    // and start from head to it before
    for (int i = 0; i < pos; i++) {
      if (nums[i] > nums[pos]) {
        return nums[i];
      }
    }

    return -1;
  }
};
