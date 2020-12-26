// http://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/description/
#include "xxx.h"
class Solution {
public:
  int getMaxLen(vector<int> &nums) {
    const int n = nums.size();
    int ret = 0;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n && nums[j] != 0) {
        j++;
      }
      // count neg
      int cneg = 0;
      vector<int> idx;
      for (int k = i; k < j; ++k) {
        if (nums[k] < 0) {
          ++cneg;
          idx.push_back(k);
        }
      }
      // odd
      if (cneg & 1) {
        // 1. 从开始到最后一个负数之前
        // 2. 从最开始一个负数的下一个位置到j
        // 可以将vector优化掉，作两个变量
        ret = max(ret, max(idx.back() - 1 - i + 1, j - (idx.front() + 1)));
      } else {
        ret = max(ret, j - i);
      }

      i = j + 1;
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{-1, 2};
  auto ret = so.getMaxLen(input);
}
