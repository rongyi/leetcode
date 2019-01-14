// http://leetcode.com/problems/maximum-subarray/description/
#include "xxx.h"

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    const int n = nums.size();
    if (n == 0) {
      return 0;
    }
    int cur_sum = 0;
    int ret = nums[0];
    for (int i = 0; i < n; ++i) {
      // 对于每一个元素，有两种选择：
      // 1. 加入前面的子数组，增加前面子数组的和
      // 2. 作为独立子数组的第一个元素
      // 判断条件就是对前面的子数组和有没有利，即能增加，如果不能，滚蛋
      auto plus = cur_sum + nums[i];
      if (plus > nums[i]) {
        cur_sum = plus;
      } else {
        cur_sum = nums[i];
      }
      ret = max(ret, cur_sum);
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{-1, -2, -3};
  auto ret = so.maxSubArray(input);
  cout << ret << endl;
}
