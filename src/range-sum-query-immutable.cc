// http://leetcode.com/problems/range-sum-query-immutable/description/
#include "simpleone.h"

class NumArray {
public:
  NumArray(vector<int> nums) {
    int cur = 0;
    sum_.resize(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      cur += nums[i];
      sum_[i] = cur;
    }
  }

  int sumRange(int i, int j) {
    if (i <= 0) {
      return sum_[j];
    }
    return sum_[j] - sum_[i - 1];
  }

private:
  vector<int> sum_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

int main() {
  vector<int> input{-2, 0, 3, -5, 2, -1};
  NumArray so(input);
  auto ret = so.sumRange(0, 2);
  cout << ret << endl;
}
