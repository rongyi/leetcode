// http://leetcode.com/problems/next-greater-element-i/description/
#include "xxx.h"

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
    unordered_map<int, int> index;
    for (int i = 0; i < nums.size(); ++i) {
      index[nums[i]] = i;
    }
    vector<int> ret;

    for (int i = 0; i < findNums.size(); ++i) {
      ret.push_back(nextGreater(nums, index[findNums[i]]));
    }
    return ret;
  }

private:
  int nextGreater(vector<int> &nums, int start) {
    for (int i = start + 1; i < nums.size(); ++i) {
      if (nums[i] > nums[start]) {
        return nums[i];
      }
    }
    return -1;
  }
};
