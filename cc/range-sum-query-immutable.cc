// http://leetcode.com/problems/range-sum-query-immutable/description/
#include "xxx.hpp"

class NumArray {
public:
  NumArray(vector<int> &nums) {
    int sz = nums.size();
    prefix_.resize(sz + 1);
    for (int i = 0; i < sz; i++) {
      prefix_[i + 1] = prefix_[i] + nums[i];
    }
  }

  int sumRange(int left, int right) {
    return prefix_[right + 1] - prefix_[left];
  }

private:
  vector<int> prefix_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
