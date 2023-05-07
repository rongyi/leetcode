// http://leetcode.com/problems/range-sum-query-mutable/description/
#include "xxx.hpp"

struct Bit {
  // 1 indexed
  Bit(int n) { prefix_bit_ = vector<int>(n, 0); }
  void update(int idx, int val) {
    // wtf is i & (-i) ?
    // 1000100 get the lowbit of 1000100 ? -> 100
    // 1. 1000100 -> 0111011
    // 2. + 1 -> 0111100
    // 3. & origin -> 0111100 & 1000100 -> 100
    // the 1. & 2. combine is neg = (complement - 1) + 1
    for (int i = idx; i < prefix_bit_.size(); i += i & (-i)) {
      prefix_bit_[i] += val;
    }
  }

  int getsum(int idx) {
    int sum = 0;
    for (int i = idx; i > 0; i -= i & (-i)) {
      sum += prefix_bit_[i];
    }
    return sum;
  }
  vector<int> prefix_bit_;
};

// using BIT is the way out
class NumArray {

public:
  NumArray(vector<int> &nums) : b_(nums.size() + 1) {
    nums_ = nums;
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
      b_.update(i + 1, nums[i]);
    }
  }

  void update(int index, int val) {
    int diff = val - nums_[index];
    b_.update(index + 1, diff);
    nums_[index] = val;
  }

  int sumRange(int left, int right) {
    return b_.getsum(right + 1) - b_.getsum(left);
  }

private:
  Bit b_;
  vector<int> nums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

