// http://leetcode.com/problems/range-sum-query-mutable/description/
#include "xxx.h"

class NumArray {
public:
  NumArray(vector<int> nums) {
    nums_ = nums;
    const int n = nums.size();
    if (n == 0) {
      return;
    }
    cache_.resize(n);

    cache_[0] = nums[0];
    for (int i = 1; i < n; i++) {
      cache_[i] = cache_[i - 1] + nums[i];
    }
  }

  void update(int i, int val) {
    auto diff = val - nums_[i];
    for (int j = i; j < cache_.size(); j++) {
      cache_[j] += diff;
    }
    nums_[i] = val;
  }

  int sumRange(int i, int j) {
    if (i == 0) {
      return cache_[j];
    }
    return cache_[j] - cache_[i - 1];
  }
private:
  vector<int> cache_;
  vector<int> nums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
